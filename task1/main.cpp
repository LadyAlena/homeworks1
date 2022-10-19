#include <iostream>

#include <vector>

#include <algorithm>

template<typename T>
void printContainer(const T& container) {
	
	for (const auto& elements : container) {
		std::cout << elements << " ";
	}

	std::cout << std::endl;
}

int main(int argc, char** argv) {

#ifdef _WIN32
	setlocale(LC_ALL, "ru");
#endif

	std::vector<int> v = { 4, 7, 9, 14, 12 };

	printContainer(v);

	std::for_each(v.begin(), v.end(), 
		[](auto& value) {

			if (value % 2 != 0) { value *= 3; }

		});

	printContainer(v);

	return 0;
}