#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

void build_tridiag(const char *input, const char *output, bool natural);

void ncb_spline(const char *points, const char *coeffs, const char *poly_out);

enum spline_type {natural, clamped};

void build_spline()
