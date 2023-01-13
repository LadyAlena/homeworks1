#include <iostream>
#include <vector>
#include <string>
#include <functional>

int main(int argc, char** argv) {

	std::vector<double> angles{30, 60, 90};

	auto Sin = [](double angle) {std::cout << " sin: " << sin(angle); };
	auto Cos = [](double angle) {std::cout << " cos: " << cos(angle); };

	std::vector<std::function<void(double)>> functions{Sin, Cos};

	auto double2str = [](double angle) { return " " +std::to_string(static_cast<int>(angle)) + " * 3.1415926 / 180, "; };
	auto deg2rad = [](double angle) { const double PI = 3.1415926; return angle *= (PI / 180); };

	std::cout << "[Входные данные:]";
	for (auto& angle : angles) {
		std::cout << double2str(angle);
		angle = deg2rad(angle);
	}
	std::cout << "\b\b" << " // перевод из градусов в радианы" << std::endl;

	std::cout << "[Выходные данные:]" << std::endl;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}

	return 0;
}