/**
 * @file viewer.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SMART_Viewer_H_
#define SMART_Viewer_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data-samples/color.h"
#include "Functions/affine.h"
#define SIZE 2000

#define CORRECTLY 1
#define ERROR 1
#define OK 0

typedef struct dataStruct {
  int countVertexes;
  int countFacets;
  double* dataVertexes;
  int* dataFacets;
  double minVertexesX;
  double maxVertexesX;
  double minVertexesY;
  double maxVertexesY;
  double minVertexesZ;
  double maxVertexesZ;
  int countFaset;

} dataStruct;

int countVertexesFacets(char* fname, dataStruct* data);
dataStruct parser(char* fname);  //, int* V, int* F
int parserVertexes(char* fname, dataStruct* data);
int parserFacets(char* fname, dataStruct* data);
// void       maxMinVertex(dataStruct* dataStr);

void initData(dataStruct* data);
void cleanData(dataStruct* data);
void printData(dataStruct* data);
void exitData(dataStruct* data);

#endif  //  SMART_Viewer_H
