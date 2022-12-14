#include <iostream>

#include <vector>
#include <string>
#include <variant>
#include <functional>

#include <algorithm>
#include <numeric>

struct pi_CONST {
	double rad = 3.1415926;
	int deg = 180;
} pi;

int main(int argc, char** argv) {

	std::vector<double> angles = { 30, 60, 90 };

	std::string deg_to_rad_str = " * " + std::to_string(pi.rad) + " / " + std::to_string(pi.deg);
 
	std::cout << "[Входные данные]: ";

	std::string result = std::accumulate(std::next(angles.begin()), angles.end(), std::to_string(static_cast<int>(angles[0])) + deg_to_rad_str,
		[deg_to_rad_str](std::string angle1, int angle2) {
			return angle1 + ", " + std::to_string(angle2) + deg_to_rad_str;
		}) 
		+ " // перевод из градусов в радианы";

	std::cout << result  << std::endl;

	for (auto& angle : angles) {
		angle *= (pi.rad / pi.deg);
	}

	std::vector<std::function<void(double)>> functions {
		[](double angle) { std::cout << "sin: " << std::sin(angle) << " "; },
		[](double angle) { std::cout << "cos: " << std::cos(angle) << " "; }
	};

	std::cout << "[Выходные данные]:" << std::endl;

	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}

	return 0;
}