#include <iostream>

#include "int_compare.hpp"

/*
	SORTS
*/
#include "bubble.hpp"


int main() {
	size_t length = 8;
	int a[] = {4, 2, 7, 3, 8, 3, 0, -5};

	bubble_sort<int>(a, length, &int_compare);

	for (size_t i = 0; i < length; i++) {
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;
}