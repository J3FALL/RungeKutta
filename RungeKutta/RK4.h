#pragma once
#define _USE_MATH_DEFINES
#include <cmath>                    // for trigonometry functions
#include <string> 
#include <vector>
#include <utility>

double A = 2;
double omega = M_PI;
double T = 2;
double T_terminal = 100;
double N = omega * T / (2 * M_PI);
double epsilon = 0.01;
double tau = 0.01; //time discrete step
double M_L = 200;
double T_L = 2;

std::vector<double> xd;
std::vector<double> yd;

double f_x(double  x, double  y, double  xdelay, double  ydelay, double  t);
double f_y(double  x, double  y, double  xdelay, double  ydelay, double  t);
std::pair<double, double> getNextStep(
	double  x, double  y, double  xdelay, double  ydelay, double  t,double tau);
void generate_delay(double x0, double y0, double T, double tau);
std::pair<std::vector<double>, std::vector<double>> solve(double x0, double y0, double T_initial, double T_terminal, double tau);

double f_x(double  x, double  y, double  xdelay, double  ydelay, double  t) { //Here we want to split vector a to two variables a_x and a_y
	double fx = y;															  //And treat them separatelly
	return fx;
}

double f_y(double  x, double  y, double  xdelay, double  ydelay, double  t) {
	double fy =
		A * cos(omega * t / N) - omega * omega * x +
		epsilon * xdelay * ydelay * cos(omega * t);

	return fy;
}

std::pair<double, double> getNextStep(
	double  x, double  y, double  xdelay, double  ydelay, double  t,double tau) {
	std::pair<double,double> next_step;

	double k1_x, k1_y, k2_x, k2_y, k3_x, k3_y, k4_x, k4_y, xrk, yrk;

	k1_x = tau * f_x(x, y, xdelay, ydelay, t);
	k1_y = tau * f_y(x, y, xdelay, ydelay, t);
	k2_x = tau * f_x(x + 0.5 * k1_x, y + 0.5 * k1_y, xdelay, ydelay, t + 0.5 * tau);
	k2_y = tau * f_y(x + 0.5 * k1_x, y + 0.5 * k1_y, xdelay, ydelay, t + 0.5 * tau);
	k3_x = tau * f_x(x + 0.5 * k2_x, y + 0.5 * k2_y, xdelay, ydelay, t + 0.5 * tau);
	k3_y = tau * f_y(x + 0.5 * k2_x, y + 0.5 * k2_y, xdelay, ydelay, t + 0.5 * tau);
	k4_x = tau * f_x(x + k3_x, y + k3_y, xdelay, ydelay, t + tau);
	k4_y = tau * f_y(x + k3_x, y + k3_y, xdelay, ydelay, t + tau);

	xrk = x + (k1_x + 2 * k2_x + 2 * k3_x + k4_x) / 6;
	yrk = y + (k1_y + 2 * k2_y + 2 * k3_y + k4_y) / 6;

	next_step.first = xrk;
	next_step.second = yrk;
	return next_step;
}

void generate_delay(double x0, double y0, double T_terminal, double tau) {
	for (double delay = -T_terminal; delay < 0; delay += tau) {
		xd.push_back(0);//TODO:Add random here(?)
		yd.push_back(0);//TODO:Add random here(?)
	}
	xd.push_back(x0);
	yd.push_back(y0);
}

std::pair<std::vector<double>, std::vector<double>> solve(double x0, double y0, double T_initial, double T_terminal, double tau) {
	int n = (T_terminal - T_initial) / tau; //Number of integer time steps;
	std::vector<double> xvec;
	std::vector<double> yvec;
	std::pair<std::vector<double>, std::vector<double>> slnvec;
	xd.clear();
	yd.clear();

	generate_delay(x0, y0, T_terminal, tau);

	xvec.push_back(xd[xd.size() - 1]);//Here we want to add 'real' initial conditions without delay,i.e. the last element of delayed vector
	yvec.push_back(yd[yd.size() - 1]);
	for (int i = 0; i < n; i++) {//Now we doing RK steps directly
		std::pair<double, double> nextStep = getNextStep(
			xvec[xvec.size() - 1], yvec[yvec.size() - 1],
			xd[xd.size() - 1 - 7], yd[yd.size() - 1 - 7], T_initial+i*tau,tau);
		xvec.push_back(nextStep.first);
		yvec.push_back(nextStep.second);
		xd.push_back(xvec[xvec.size() - 1]);
		yd.push_back(yvec[yvec.size() - 1]);
	}
	slnvec.first = xvec;
	slnvec.second = yvec;
	return slnvec;
}

double Lyapunov_exp(double x0, double y0, int T, int M) {
	double l1;
	double norm_product = 1;
	std::vector<double> xl, yl, bias_x, bias_y,bias_norm;
	std::pair<std::vector<double>, std::vector<double>> sln,sln_b;
	xl.push_back(x0);
	yl.push_back(y0);
	bias_x.push_back(1);
	bias_y.push_back(1);
	bias_norm.push_back((sqrt(bias_x[bias_x.size() - 1] * bias_x[bias_x.size() - 1] + bias_y[bias_y.size() - 1] * bias_y[bias_y.size() - 1])));
	sln = solve(xl[xl.size() - 1], yl[yl.size() - 1],0,2, 0.01);
	for (int i = 0; i < M; i++) {
		bias_x[bias_x.size() - 1] = bias_x[bias_x.size() - 1] / bias_norm[bias_norm.size() - 1];
		bias_y[bias_y.size() - 1] = bias_y[bias_y.size() - 1] / bias_norm[bias_norm.size() - 1];
		sln = solve(xl[xl.size() - 1], yl[yl.size() - 1], i*T,(i+1)*T, tau);
		sln_b = solve(xl[xl.size() - 1] + bias_x[bias_x.size() - 1], yl[yl.size() - 1] + bias_y[bias_x.size() - 1], i*T, (i + 1)*T, tau);
		xl.push_back(sln.first[sln.first.size() - 1]);
		yl.push_back(sln.second[sln.second.size() - 1]);
		bias_x.push_back(sln.first[sln.first.size() - 1] - sln_b.first[sln_b.first.size() - 1]);
		bias_y.push_back(sln.second[sln.second.size() - 1] - sln_b.second[sln_b.second.size() - 1]);
		bias_norm.push_back((sqrt(bias_x[bias_x.size() - 1] * bias_x[bias_x.size() - 1] + bias_y[bias_y.size() - 1] * bias_y[bias_y.size() - 1])));
	};
	for (int i = 0; i < bias_norm.size(); i++) {
		norm_product *= bias_norm[i];
	};
	l1 = log(norm_product) / (M*T);
	return l1;
}