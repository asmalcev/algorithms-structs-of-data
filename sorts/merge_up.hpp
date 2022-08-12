#pragma once

#include "util.hpp"

#ifdef STAT
#include <iostream>
#endif

// template <typename T>
// size_t foo(
// 	T* array1,
// 	T* array2,
// 	size_t length,
// 	bool (*compare)(T, T)
// 	#ifdef STAT_LOC
// 	, size_t & step_stat,
// 	size_t & replace_stat
// 	#endif
// ) {
// 	size_t pos1 = 0;
// 	size_t pos2 = length - 1;
// 	size_t pos3 = 0;
// 	size_t last_sorted_index;

// 	array2[pos1++] = array1[pos3++];
// 	while (pos3 < length) {
// 		if (!compare(array2[pos1 - 1], array1[pos3])) {
// 			array2[pos1++] = array1[pos3++];
// 		} else {
// 			array2[pos2--] = array1[pos3++];
// 		}
// 	}

// 	if (pos2 != length - 1) {
// 		std::cout << "1\n";
// 		last_sorted_index = pos1;
// 		pos1 = 0;
// 		pos2++;
// 		pos3 = 0;

// 		if (compare(array2[pos1], array2[pos2])) {
// 			array1[pos3++] = array2[pos2++];
// 		} else {
// 			array1[pos3++] = array2[pos1++];
// 		}

// 		while (pos3 < length) {
// 			if (compare(array2[pos1], array2[pos2]) && !compare(array1[pos3 - 1], array2[pos2])) {
// 				array1[pos3++] = array2[pos2++];
// 			} else {
// 				if (last_sorted_index == pos1) break;
// 				array1[pos3++] = array2[pos1++];
// 			}
// 		}

// 		if (last_sorted_index == pos1) {
// 			std::cout << "2\n";
// 			last_sorted_index = pos2 - 1;
// 			while (pos3 < length) {
// 				array1[pos3++] = array2[pos2++];
// 			}
// 		}
// 	} else {
// 		std::cout << "3\n";
// 		last_sorted_index = length - 1;
// 	}

// 	return last_sorted_index;
// }

template <typename T>
size_t foo(
	T* array1,
	T* array2,
	size_t border,
	size_t length,
	bool (*compare)(T, T)
) {
	if (border == length) {
		return length;
	}

	if (0 < border) {
		size_t current_sorted = 0;
		size_t current_unsorted = border;
		size_t new_current_sorted = 0;
		size_t new_current_unsorted = length - 1;

		if (compare(array1[current_unsorted], array1[current_sorted])) {
			// std::cout << array1[current_sorted] << std::endl;
			array2[new_current_sorted++] = array1[current_sorted++];
		} else {
			// std::cout << array1[current_unsorted] << std::endl;
			array2[new_current_sorted++] = array1[current_unsorted++];
		}
		while (new_current_sorted < new_current_unsorted) {
			// std::cout << current_sorted << " | " << current_unsorted << std::endl;
			if (current_sorted == border || current_unsorted == length) break;

			if (compare(array1[current_unsorted], array1[current_sorted])) {
				// std::cout << array1[current_sorted] << std::endl;
				array2[new_current_sorted++] = array1[current_sorted++];
			} else {
				// std::cout << array1[current_unsorted] << " " << array2[new_current_sorted - 1] << std::endl;
				if (!compare(array2[new_current_sorted - 1], array1[current_unsorted])) {
					// std::cout << array1[current_unsorted] << std::endl;
					array2[new_current_sorted++] = array1[current_unsorted++];
				} else {
					// std::cout << "to the end " << array1[current_unsorted] << std::endl;
					array2[new_current_unsorted--] = array1[current_unsorted++];
				}
			}
		}

		while (current_sorted < border) {
			// std::cout << array1[current_sorted] << std::endl;
			array2[new_current_sorted++] = array1[current_sorted++];
		}

		while (current_unsorted < length) {
			// std::cout << array1[current_sorted] << std::endl;
			if (!compare(array2[new_current_sorted - 1], array1[current_unsorted])) {
				// std::cout << array1[current_unsorted] << std::endl;
				array2[new_current_sorted++] = array1[current_unsorted++];
			} else {
				// std::cout << "to the end " << array1[current_unsorted] << std::endl;
				array2[new_current_unsorted--] = array1[current_unsorted++];
			}
		}

		return new_current_sorted;

	} else {
		size_t pos1 = 0;
		size_t pos2 = length - 1;
		size_t pos3 = 0;

		array2[pos1++] = array1[pos3++];
		while (pos3 < length) {
			if (!compare(array2[pos1 - 1], array1[pos3])) {
				array2[pos1++] = array1[pos3++];
			} else {
				array2[pos2--] = array1[pos3++];
			}
		}

		return pos1;
	}
}

template <typename T>
T* merge_up_sort(
	T* array, size_t length, bool (*compare)(T, T)
	#ifdef STAT_LOC
	, size_t & step_stat,
	size_t & replace_stat
	#endif
) {
	T * tmp = new T[length];

	size_t border = foo(array, tmp, 0, length, compare);

	while (border != length) {
		border = foo(tmp, array, border, length, compare);

		if (border == length) {
			border = foo(array, tmp, border, length, compare);
		}
	}

	display_array(tmp, length);

	// size_t last_sorted_index = foo(array, tmp, length, compare);
	// if (last_sorted_index != length - 1) {
	// 	last_sorted_index = foo(array, tmp, length, compare);
	// }

	// std::cout << last_sorted_index << std::endl;

	// display_array(tmp, length);

	return array;
}