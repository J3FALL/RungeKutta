#pragma once


ref class RungeKuttaParams
{
public:
	double A;
	double omega;
	double T;
	double T_terminal;
	double N;
	double epsilon;
	double tau;

	RungeKuttaParams(double A, double omega, double T, double T_terminal, double epsilon, double tau) {
		this->A = A;
		this->omega = omega;
		this->T = T;
		this->T_terminal = T_terminal;
		this->N = omega * T / (2 * 3.14);
		this->epsilon = epsilon;
		this->tau = tau;
	}

};

