#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

#define SOLVE_RUN "./solve"

bool les_solve(const char *input, const char *output);

void build_vander(const char *input, const char *output);

void plot2d(const char *points, const char *poly);

void split3d(const char *input, const char *out1, const char *out2);

void plot3d(const char *points, const char *polyxy, const char *polyxz);
