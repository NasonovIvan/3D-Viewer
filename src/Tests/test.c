#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../viewer.h"
dataStruct dataStr;
// void       FreeM() {}

START_TEST(test_1) {
  countVertexesFacets("Tests/testFile_1.obj", &dataStr);
  ck_assert_int_eq(8, dataStr.countVertexes/3);
  cleanData(&dataStr);
}
END_TEST

START_TEST(test_2) {
  countVertexesFacets("Tests/testFile_1.obj", &dataStr);
  ck_assert_int_eq(36, dataStr.countFacets);
  cleanData(&dataStr);
}
END_TEST

START_TEST(test_8) {
  int res = countVertexesFacets("", &dataStr);
  ck_assert_int_eq(1, res);
  cleanData(&dataStr);
}

START_TEST(test_3) {
  char fname[] = "Tests/testFile_1.obj";
  double V[24] = {-0.500000, -0.500000, 0.500000,  0.500000,  -0.500000,
                  0.500000,  -0.500000, 0.500000,  0.500000,  0.500000,
                  0.500000,  0.500000,  -0.500000, 0.500000,  -0.500000,
                  0.500000,  0.500000,  -0.500000, -0.500000, -0.500000,
                  -0.500000, 0.500000,  -0.500000, -0.500000};
  dataStr = parser(fname);
  for (int i = 0; i < 24; i++) {
    ck_assert_double_eq(V[i], dataStr.dataVertexes[i]);
  }

  cleanData(&dataStr);
}
END_TEST

START_TEST(test_4) {
  char fname[] = "Tests/testFile_1.obj";
  int F[72] = {0, 1, 1, 2, 2, 0, 2, 1, 1, 3, 3, 2, 2, 3, 3, 4, 4, 2,
               4, 3, 3, 5, 5, 4, 4, 5, 5, 6, 6, 4, 6, 5, 5, 7, 7, 6,
               6, 7, 7, 0, 0, 6, 0, 7, 7, 1, 1, 0, 1, 7, 7, 3, 3, 1,
               3, 7, 7, 5, 5, 3, 6, 0, 0, 4, 4, 6, 4, 0, 0, 2, 2, 4};
  dataStr = parser(fname);
  for (int i = 0; i < 72; i++) {
    ck_assert_int_eq(F[i], dataStr.dataFacets[i]);
  }
  cleanData(&dataStr);
}
END_TEST

START_TEST(test_5) {
  double* p;
  p = (double*)calloc(3, sizeof(double));
  p[0] = 1.1;
  p[1] = 1.2;
  p[2] = 3.5;
  // double* shift;

  affine_scale(3, &p, 75);
  ck_assert_ldouble_eq_tol(p[0], 0.825, 1e-2);
  ck_assert_ldouble_eq_tol(p[1], 0.9, 1e-2);
  ck_assert_ldouble_eq_tol(p[2], 2.625, 1e-2);
  free(p);
  // free(shift);
}

START_TEST(test_6) {
  double* p;
  p = (double*)calloc(3, sizeof(double));
  p[0] = 1.1;
  p[1] = 1.2;
  p[2] = 3.5;
  double* move = (double*)calloc(3, sizeof(double));
  move[0] = 180.0;
  move[1] = 360.0;
  move[2] = 0.0;

  affine_move(3, &p, move);
  ck_assert_ldouble_eq_tol(p[0], 181.1, 1e-2);
  ck_assert_ldouble_eq_tol(p[1], 361.2, 1e-2);
  ck_assert_ldouble_eq_tol(p[2], 3.5, 1e-2);
  free(p);
  free(move);
}

START_TEST(test_7) {
  double* p;
  p = (double*)calloc(3, sizeof(double));
  p[0] = 1.1;
  p[1] = 1.2;
  p[2] = 3.5;
  double* move = (double*)calloc(3, sizeof(double));
  move[0] = 180.0;
  move[1] = 360.0;
  move[2] = 0.0;

  affine_rotate(3, &p, move);
  ck_assert_ldouble_eq_tol(p[0], 1.1, 1e-2);
  ck_assert_ldouble_eq_tol(p[1], -1.2, 1e-2);
  ck_assert_ldouble_eq_tol(p[2], -3.5, 1e-2);
  free(p);
  free(move);
}

int main(void) {
  Suite* s1 = suite_create("Core");
  TCase* tc = tcase_create("Core");
  SRunner* sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc);

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
