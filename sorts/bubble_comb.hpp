#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
T* bubble_comb_sort(T* array, size_t length, bool (*compare)(T, T)) {
	#ifdef STAT
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif

	const double factor = 1.2473309; // magic number for better perfomance
	size_t step = length - 1;

	while (step >= 1) {
		for (size_t i = 0; i + step < length; i++) {
			#ifdef STAT
			step_stat++;
			#endif

			if (array[i] > array[i + step]) {
				std::swap(array[i], array[i + step]);

				#ifdef STAT
				replace_stat++;
				#endif
			}
		}

		step /= factor;
	}

	#ifdef STAT
	std::cout << "bubble_comb_sort.stepStat: " << step_stat << std::endl;
	std::cout << "bubble_comb_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}