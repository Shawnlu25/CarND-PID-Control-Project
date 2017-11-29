#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	// Derivative error = old cte - cte
	d_error = (cte - p_error);

	// Proportion error = cte
	p_error = cte;

	// Integral error = Integral error + cte
	i_error += cte;
}

double PID::TotalError() {
	return -Kp * p_error - Kd * d_error - Ki * i_error;
}

