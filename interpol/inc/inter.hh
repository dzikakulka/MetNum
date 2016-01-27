#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>

#ifndef _FH
#define _FH
#include "../inc/function.hh"
#endif


std::string build_lpoly(Dataset points);

void build_vander(Dataset points, const char *output, int dim);

std::string lpoly(const char *coeffs);

//void plot2d(const char *points, const char *poly);

//void split3d(const char *input, const char *out1, const char *out2);

//void plot3d(const char *points, const char *polyxy, const char *polyxz);
