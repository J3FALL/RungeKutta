#include "RK4.h"

double A = 2;
double omega = M_PI;
double T = 2;
double T_terminal = 2;
double N = omega * T / (2 * M_PI);
double epsilon = 0.01;
double tau = 0.1; //time discrete step

/*double rkstep_x(double  x, double  y, double  xdelay, double  ydelay, double  t) {
double k1_x, k1_y, k2_x, k2_y, k3_x, k3_y, k4_x, k4_y, xrk, yrk;
k1_x = tau * f_x(x, y, xdelay, ydelay, t);
k1_y = tau * f_y(x, y, xdelay, ydelay, t);
k2_x = tau * f_x(x + 0.5*k1_x, y + 0.5*k1_y, xdelay, ydelay, t + 0.5*tau);
k2_y = tau * f_y(x + 0.5*k1_x, y + 0.5*k1_y, xdelay, ydelay, t + 0.5*tau);
k3_x = tau * f_x(x + 0.5*k2_x, y + 0.5*k2_y, xdelay, ydelay, t + 0.5*tau);
k3_y = tau * f_y(x + 0.5*k2_x, y + 0.5*k2_y, xdelay, ydelay, t + 0.5*tau);
k4_x = tau * f_x(x + k3_x, y + k3_y, xdelay, ydelay, t + tau);
k4_y = tau * f_y(x + k3_x, y + k3_y, xdelay, ydelay, t + tau);
xrk = x + (k1_x + 2 * k2_x + 2 * k3_x + k4_x) / 6;
yrk = y + (k1_y + 2 * k2_y + 2 * k3_y + k4_y) / 6;
return xrk;
}

double rkstep_y(double  x, double  y, double  xdelay, double  ydelay, double  t) {
double k1_x, k1_y, k2_x, k2_y, k3_x, k3_y, k4_x, k4_y, xrk, yrk;
k1_x = tau * f_x(x, y, xdelay, ydelay, t);
k1_y = tau * f_y(x, y, xdelay, ydelay, t);
k2_x = tau * f_x(x + 0.5*k1_x, y + 0.5*k1_y, xdelay, ydelay, t + 0.5*tau);
k2_y = tau * f_y(x + 0.5*k1_x, y + 0.5*k1_y, xdelay, ydelay, t + 0.5*tau);
k3_x = tau * f_x(x + 0.5*k2_x, y + 0.5*k2_y, xdelay, ydelay, t + 0.5*tau);
k3_y = tau * f_y(x + 0.5*k2_x, y + 0.5*k2_y, xdelay, ydelay, t + 0.5*tau);
k4_x = tau * f_x(x + k3_x, y + k3_y, xdelay, ydelay, t + tau);
k4_y = tau * f_y(x + k3_x, y + k3_y, xdelay, ydelay, t + tau);
xrk = x + (k1_x + 2 * k2_x + 2 * k3_x + k4_x) / 6;
yrk = y + (k1_y + 2 * k2_y + 2 * k3_y + k4_y) / 6;
return yrk;
}

void generate_delay() {
for (double delay = -T; delay < 0; delay += tau) {
xd.push_back(0);//TODO:Add random here(?)
yd.push_back(0);//TODO:Add random here(?)
}
}


void rk() {
xvec.push_back(xd[xd.size() - 1]);//Here we want to add 'real' initial conditions without delay,i.e. the last element of delayed vector
yvec.push_back(yd[yd.size() - 1]);
for (double time = 0; time <= T_terminal; time += tau) {//Now we doing RK steps directly
xvec.push_back(rkstep_x(xvec[xvec.size() - 1], yvec[yvec.size() - 1], xd[xd.size() - 1 - 7], yd[yd.size() - 1 - 7], time));
yvec.push_back(rkstep_y(xvec[xvec.size() - 1], yvec[yvec.size() - 1], xd[xd.size() - 1 - 7], yd[yd.size() - 1 - 7], time));
xd.push_back(xvec[xvec.size() - 1]);//TODO:Add random here(?)
yd.push_back(yvec[xvec.size() - 1]);//TODO:Add random here(?)
}
}
*/

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
	double  x, double  y, double  xdelay, double  ydelay, double  t) {

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

	return std::make_pair(xrk, yrk);
}

void generate_delay(double T, double tau) {
	for (double delay = -T; delay < 0; delay += tau) {
		xd.push_back(0);//TODO:Add random here(?)
		yd.push_back(0);//TODO:Add random here(?)
	}
}

void solve() {
	xvec.clear();
	yvec.clear();

	generate_delay(T, tau);

	xvec.push_back(xd[xd.size() - 1]);//Here we want to add 'real' initial conditions without delay,i.e. the last element of delayed vector
	yvec.push_back(yd[yd.size() - 1]);
	for (double time = 0; time <= T_terminal; time += tau) {//Now we doing RK steps directly
		std::pair<double, double> nextStep = getNextStep(
			xvec[xvec.size() - 1], yvec[yvec.size() - 1],
			xd[xd.size() - 1 - 7], yd[yd.size() - 1 - 7], time);
		xvec.push_back(nextStep.first);
		yvec.push_back(nextStep.second);

		xd.push_back(xvec[xvec.size() - 1]);//TODO:Add random here(?)
		yd.push_back(yvec[xvec.size() - 1]);//TODO:Add random here(?)
	}
}
