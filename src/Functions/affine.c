/**
 * @file affine.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "affine.h"
#define PI 3.14159265

/**
 * Affine scale
 \param[in] l length of coordinate array
 \param[in,out] v coordinate array
 \param[in] size percent to resize model
*/
void affine_scale(int l, double **v, double size) {
  if (size == 0) size = 100.0;
  for (int i = 0; i < l; i++) (*v)[i] = (*v)[i] * size / 100;
}

/**
 * Affine move
 \param[in] l length of coordinate array
 \param[in,out] v coordinate array
 \param[in] shift coordinates to shift model (x, y, z)
*/

void affine_move(int l, double **v, const double *shift) {
  if (l % 3 == 0) {
    for (int i = 0; i < l; i++) {
      (*v)[i] = (*v)[i] + shift[i % 3];
    }
  }
}

/**
 * Affine rotate
 \param[in] l length of coordinate array
 \param[in,out] v coordinate array
 \param[in] rotate degrees to rotate around certain axis
*/
void affine_rotate(int l, double **v, double *rotate) {
  for (int i = 0; i < 3; i++) rotate[i] = rotate[i] * PI / 180;
  if (l % 3 == 0) {
    double v_temp[3];
    for (int i = 0; i < l; i += 3) {
      for (int j = 0; j < 3; j++) v_temp[j] = (*v)[i + j];
      (*v)[i + 1] = v_temp[1] * cos(rotate[0]) - v_temp[2] * sin(rotate[0]);
      (*v)[i + 2] = v_temp[1] * sin(rotate[0]) + v_temp[2] * cos(rotate[0]);
      for (int j = 0; j < 3; j++) v_temp[j] = (*v)[i + j];
      (*v)[i] = v_temp[0] * cos(rotate[1]) + v_temp[2] * sin(rotate[1]);
      (*v)[i + 2] = -v_temp[0] * sin(rotate[1]) + v_temp[2] * cos(rotate[1]);
      for (int j = 0; j < 3; j++) v_temp[j] = (*v)[i + j];
      (*v)[i] = v_temp[0] * cos(rotate[2]) - v_temp[1] * sin(rotate[2]);
      (*v)[i + 1] = v_temp[0] * sin(rotate[2]) + v_temp[1] * cos(rotate[2]);
    }
  }
}
