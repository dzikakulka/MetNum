#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#ifndef _FH
#define _FH
#include "../inc/function.hh"
#endif

enum spline_type {natural, clamped};

void build_tridiag(Dataset input, spline_type type, const char *output, int dim);

std::string ncb_spline(Dataset points, const char *coeffs, int dim);

std::string build_spline(Dataset input, spline_type type);
