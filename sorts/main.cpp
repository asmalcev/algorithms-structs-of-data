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
#include "bubble_comb.hpp"


int main() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};
	// std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	// bubble_sort<int>(a.data(), length, &compare);
	// bubble_bug_sort<int>(a.data(), length, &compare);
	bubble_comb_sort<int>(a.data(), length, &compare);

	for (size_t i = 0; i < length; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}