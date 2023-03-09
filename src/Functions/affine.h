//#include "../viewer.h"
/**
 * @file affine.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <math.h>

void affine_scale(int, double **, double);
void affine_move(int, double **, const double *);
void affine_rotate(int l, double **v, double *rotate);
