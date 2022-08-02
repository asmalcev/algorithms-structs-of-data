#include <iostream>
#include <array>

#include "util.hpp"

/*
	Used to display count of replacements
*/
#define STAT
#define STAT_LOC

/*
	SORTS
*/
#include "bubble.hpp"
#include "bubble_bug.hpp"
#include "bubble_comb.hpp"
#include "shaker.hpp"
#include "oddeven.hpp"
#include "heap.hpp"
#include "merge.hpp"


int main() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};
	// std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};
	// std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};
	// std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	#ifdef STAT
	#ifdef STAT_LOC
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif
	#endif

	// bubble_sort<int>(a.data(), length, &compare);
	// bubble_bug_sort<int>(a.data(), length, &compare);
	// bubble_comb_sort<int>(a.data(), length, &compare);
	// shaker_sort<int>(a.data(), length, &compare);
	// oddeven_sort<int>(a.data(), length, &compare);
	// heap_sort<int>(a.data(), length, &compare);
	merge_sort<int>(a.data(), length, &compare, step_stat, replace_stat);

	#ifdef STAT
	#ifdef STAT_LOC
	std::cout << "sort.stepStat: " << step_stat << std::endl;
	std::cout << "sort.replaceCount: " << replace_stat << std::endl;
	#endif
	#endif

	display_array<int>(a.data(), length);
}