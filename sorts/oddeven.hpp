#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
T* oddeven_sort(T* array, size_t length, bool (*compare)(T, T)) {
	#ifdef STAT
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif

	for (size_t i = 0; i < length; i++) {
		for (size_t j = (i % 2) ? 0 : 1; j + 1 < length; j += 2) {
			#ifdef STAT
			step_stat++;
			#endif

			if (array[j] > array[j + 1]) {
				std::swap(array[j], array[j + 1]);

				#ifdef STAT
				replace_stat++;
				#endif
			}
		}
	}

	#ifdef STAT
	std::cout << "oddeven_sort.stepStat: " << step_stat << std::endl;
	std::cout << "oddeven_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}