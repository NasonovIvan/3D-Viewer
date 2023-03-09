/**
 * @file parser.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "../viewer.h"
/**
 * @brief Парсим, главная функция
 *
 * @param fname      имя файла который откываем
 * @param dataStr    в эту структуру записываем колличество v & f
 * @return           int проверок пока нет
 */
dataStruct parser(char *fname) {
  dataStruct dataStr;
  initData(&dataStr);
  countVertexesFacets(fname, &dataStr);
  parserVertexes(fname, &dataStr);
  parserFacets(fname, &dataStr);
  return dataStr;
}

/**
 * @brief       init struct
 *
 * @param dataStr
 */
void initData(dataStruct *dataStr) {
  dataStr->countFacets = 0;
  dataStr->countVertexes = 0;
  dataStr->countFaset = 0;
  //  dataStr->minVertexes   = 0;
  //  dataStr->maxVertexes   = 0;
}
/**
 * @brief            Проходит по файлу и считает количество строк v и f
 *
 * @param fname      имя файла который откываем
 * @param dataStr    в эту структуру записываем данные
 */
int countVertexesFacets(char *fname, dataStruct *dataStr) {
  int res = OK;
  FILE *file = fopen(fname, "r");

  if (file == NULL) {
    printf("No such file or directory\n");
    res = ERROR;
  } else {
    size_t fBufSize = SIZE;
    char *strF = (char *)calloc(fBufSize, sizeof(char));
    while (getline(&strF, &fBufSize, file) != -1) {
      if (strF[0] == 'v' && strF[1] == ' ') dataStr->countVertexes++;
      if (strF[0] == 'f' && strF[1] == ' ') dataStr->countFaset++;
      for (int i = 0; strF[i] != '\n'; i++) {
        if (strF[0] == 'f' && strF[1] == ' ' && strF[i] == ' ')
          dataStr->countFacets++;
      }
    }
    dataStr->countVertexes *= 3;
    if (strF) free(strF);
    fclose(file);
  }
  return res;
}

/**
 * @brief            записываем в структуру v
 *
 * @param fname      имя и расположение obj файла
 * @param dataStr    структура для записи
 * @return           int
 */
int parserVertexes(char *fname, dataStruct *dataStr) {  // Nataly
  int res = OK;
  int i = 0;
  FILE *file = fopen(fname, "r");
  dataStr->dataVertexes =
      (double *)calloc(dataStr->countVertexes + 1, sizeof(double));
  char *strF = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&strF, &len, file)) != -1) {
    if (strF[0] == 'v' && strF[1] == ' ') {
      int j = 0;
      char *pchF = strtok(strF, " v");
      while (pchF != NULL && j < 3) {
        dataStr->dataVertexes[i] = atof(pchF);
        pchF = strtok(NULL, " ");
        i++;
        j++;
      }
    }
  }
  free(strF);
  fclose(file);
  return res;
}
/**
 * @brief           записываем в структуру f
 *
 * @param fname     имя и расположение obj файла
 * @param dataStr   структура для записи
 * @return          int
 */

int parserFacets(char *fname, dataStruct *dataStr) {
  int res = OK;
  int i = 0;
  dataStr->dataFacets = (int *)calloc(dataStr->countFacets * 2 + 1,
                                      sizeof(int));  // *2 из-за индексов
  FILE *file = fopen(fname, "r");

  char *strF = NULL;
  int *bufInt = (int *)calloc(dataStr->countFacets * 3, sizeof(int));
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&strF, &len, file)) != -1) {
    int sizeStrF = strlen(strF);
    if (strF[0] == 'f' && strF[1] == ' ') {
      if (strF[sizeStrF - 3] == ' ' && strF[sizeStrF - 2] == '\r' &&
          strF[sizeStrF - 1] == '\n') {
        strF[sizeStrF - 3] = '\n';
      }
      if (strF[sizeStrF - 2] == ' ' && strF[sizeStrF - 1] == '\n') {
        strF[sizeStrF - 2] = '\n';
      }
      int flag = 0;
      char *pchF = strtok(strF, " f");
      int buf = atoi(pchF);  // after  f get int in buf
      while (pchF != NULL) {
        for (size_t k = 0; k < strlen(pchF); k++)
          if (pchF[k] == '\n') flag = 2;
        if (flag == 2) {
          bufInt[i] = atoi(pchF) - 1;
          i++;
          bufInt[i] = atoi(pchF) - 1;
          i++;
          bufInt[i] = buf - 1;
          i++;
          bufInt[i] = -1000;
          i++;
        }

        else {
          bufInt[i] = atoi(pchF) - 1;
          i++;
          bufInt[i] = atoi(pchF) - 1;
          i++;
        }
        pchF = strtok(NULL, " ");
      }
    }
  }

  int j = 1;
  int f = 0;
  for (f = 0, j = 1; f <= dataStr->countFacets * 2; j++, f++) {
    if (f == 0) dataStr->dataFacets[f] = bufInt[j];
    if (bufInt[j] != -1000) dataStr->dataFacets[f] = bufInt[j];
    if (bufInt[j] == -1000) {
      j++;
      dataStr->dataFacets[f] = bufInt[j];
      j++;
    }
  }
  free(strF);
  fclose(file);
  free(bufInt);
  return res;
}

/**
 * @brief       Чистим память
 *
 * @param dataStr
 */
void cleanData(dataStruct *dataStr) {
  free(dataStr->dataVertexes);
  free(dataStr->dataFacets);
  dataStr->countFacets = 0;
  dataStr->countVertexes = 0;
}
