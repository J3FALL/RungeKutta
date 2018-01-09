#pragma once
#include "RungeKuttaParams.h"
#include <cmath>                    // for trigonometry functions
#include <string> 
#include <vector>

std::vector<double> xd;
std::vector<double> yd;
std::vector<double> xvec;
std::vector<double> yvec;

double f_x(double  x, double  y, double  xdelay, double  ydelay, double  t);
double f_y(double  x, double  y, double  xdelay, double  ydelay, double  t, RungeKuttaParams^ params);
std::pair<double, double> getNextStep(
	double  x, double  y, double  xdelay, double  ydelay, double  t, RungeKuttaParams^ params);
void generate_delay(double T, double tau);
void solve(RungeKuttaParams^ params);