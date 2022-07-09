#include <iostream>
#include <array>

#include "compare.hpp"

/*
	Used to display count of replacements
*/
#define STAT

/*
	SORTS
*/
#include "bubble.hpp"
#include "bubble_bug.hpp"


int main() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	// bubble_sort<int>(a, length, &compare);
	bubble_bug_sort<int>(a.data(), length, &compare);

	for (size_t i = 0; i < length; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}