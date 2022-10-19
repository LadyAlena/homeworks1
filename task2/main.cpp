#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <variant>

template<typename T>
void printContainer(const T& container) {

	for (const auto& elements : container) {
		std::cout << elements << " ";
	}

	std::cout << std::endl;
}

std::variant<int, std::string, std::vector<int>> get_variant() {
	
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}

	return result;
}

int main(int argc, char** argv) {

#ifdef _WIN32
	setlocale(LC_ALL, "ru");
#endif

	auto result_ = get_variant();

	if (std::holds_alternative<int>(result_)) {
		auto result_int = std::get<int>(result_);
		std::cout << result_int*2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(result_)) {
		auto result_string = std::get<std::string>(result_);
		std::cout << result_string << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(result_)) {
		auto result_vector = std::get<std::vector<int>>(result_);
		printContainer(result_vector);
	}

	return 0;
}