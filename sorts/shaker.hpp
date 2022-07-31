#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
T* shaker_sort(T* array, size_t length, bool (*compare)(T, T)) {
	#ifdef STAT
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif

	size_t control = length - 1;
	size_t left = 0;
	size_t right = length - 1;

	do {
		for (size_t i = left; i < right; i++) {
			#ifdef STAT
			step_stat++;
			#endif

			if (compare(array[i], array[i + 1])) {
				std::swap(array[i], array[i + 1]);
				control = i;

				#ifdef STAT
				replace_stat++;
				#endif
			}
		}

		right = control;

		for (size_t i = right; i > left; i--) {
			#ifdef STAT
			step_stat++;
			#endif

			if (compare(array[i - 1], array[i])) {
				std::swap(array[i - 1], array[i]);
				control = i;

				#ifdef STAT
				replace_stat++;
				#endif
			}
		}

		left = control;

	} while (left < right);

	#ifdef STAT
	std::cout << "shaker_sort.stepStat: " << step_stat << std::endl;
	std::cout << "shaker_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}