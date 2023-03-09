#ifndef COLOR_H_
#define COLOR_H_
// #include "../src/smart_Calc.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET  "\033[0m"
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE  "\033[1;37m"
#define GREEN  "\033[1;32m"
#define BLUE   "\033[1;34m"
#define BLUE_T "\033[1;47m"  // белый
#define BLUE_A "\033[1;46m"  // фиалковый
#define BLUE_B "\033[1;45m"  // сиренивый
#define BLUE_C "\033[1;44m"
#define BLUE_D "\033[1;43m"
#define BLUE_E "\033[1;42m"
#define BLUE_F "\033[1;41m"

#define OK              0
#define FAIL            1
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
// #define SIZE 256

#endif  // COLOR_H_