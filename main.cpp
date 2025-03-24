#include <iostream>
#include <cmath>
#include "capacitor.h"

int main() {
	double dt = 1e-10;
	double final_time = 5e-6;
	int steps = static_cast<int>(final_time / dt);
	double R = 1000;
	double C = 100e-12;
	double I_t = 1e-2;
	double V0 = 10.0;
	Capacitor cap1 {new double[steps], new double[steps], new double[steps], C};
	Capacitor cap2 {new double[steps], new double[steps], new double[steps], C};

	std::cout << "\nConstant Current:\n";
	cap1.time[0] = 0.0;
	cap1.voltage[0] = 0.0;
	cap1.current[0] = I_t;

	for (int i = 1; i < steps; ++i) {
		cap1.time[i] = i * dt;
		cap1.voltage[i] = cap1.voltage[i - 1] + cap1.current[i - 1] * dt / cap1.C;
		cap1.current[i] = I_t;
		if (i % 200 == 0)
			std::cout << "Time: " << cap1.time[i] << "s, Voltage: " << cap1.voltage[i] << " V, Current: " << cap1.current[i] << " A\n";
	}

	delete[] cap1.time;
	delete[] cap1.voltage;
	delete[] cap1.current;

	std::cout << "\nConstant Voltage:\n";

	cap2.time[0] = 0.0;
	cap2.voltage[0] = 0.0;
	cap2.current[0] = V0 / R;

	for (int i = 1; i < steps; ++i) {
		cap2.time[i] = i * dt;
		cap2.current[i] = cap2.current[i - 1] - (cap2.current[i - 1] / (R * cap2.C)) * dt;
		cap2.voltage[i] = V0 - cap2.current[i] * R;
		if (i % 200 == 0)
			std::cout << "Time: " << cap2.time[i] <<" s, Voltage: " << cap2.voltage[i] << " V, Current: " << cap2.current[i] << " A\n";
	}

	delete[] cap2.time;
	delete[] cap2.voltage;
	delete[] cap2.current;
	return 0;
}



