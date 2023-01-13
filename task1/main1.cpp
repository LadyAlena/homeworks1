#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char** argv) {

	std::vector<int> v = { 4, 7, 9, 14, 12 };

	auto print_v = [&v]() {
	
		for (const auto& el : v) {
			std::cout << el << " ";
		}

	};

	std::cout << "Входные данные: ";
	print_v();

	auto is_it_an_odd_number = [](int& value) { return value % 2 != 0; };

	for (auto& el : v) {
		if (is_it_an_odd_number(el)) {
			el *= 3;
		}
	}

	std::cout << std::endl << "Выходные данные: ";
	print_v();

	return 0;
}