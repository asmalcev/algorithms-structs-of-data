#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
T* bubble_sort(T* array, size_t length, bool (*compare)(T, T)) {
	#ifdef STAT
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif

	bool was_replace = false;

	for (size_t i = 0; i < length - 1; i++) {
		was_replace = false;

		for (size_t j = 0; j < length - i - 1; j++) {

			#ifdef STAT
			step_stat++;
			#endif

			if (compare(array[j], array[j + 1])) {
				std::swap(array[j], array[j + 1]);

				was_replace = true;

				#ifdef STAT
				replace_stat++;
				#endif
			}
		}

		if (!was_replace) {
			break;
		}
	}

	#ifdef STAT
	std::cout << "bubble_sort.stepStat: " << step_stat << std::endl;
	std::cout << "bubble_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}