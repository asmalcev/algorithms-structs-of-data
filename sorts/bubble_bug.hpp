#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
T* bubble_bug_sort(T* array, size_t length, bool (*compare)(T, T)) {
	#ifdef STAT
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif

	int di = 1;
	for (size_t j = 0; j < length - 1; j++) {
		for (size_t i = 0; i < length - 1; i += di) {

			#ifdef STAT
			step_stat++;
			#endif

			if (di > 0) {
				if (compare(array[i], array[i + 1])) {
					T tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;

					#ifdef STAT
					replace_stat++;
					#endif

					if (i > 1) {
						di = -1;
						i--;
					}
				}
			} else {
				if (compare(array[i - 1], array[i])) {
					T tmp = array[i];
					array[i] = array[i - 1];
					array[i - 1] = tmp;

					#ifdef STAT
					replace_stat++;
					#endif

				} else if (i < length - 1) {
					di = 1;
				}
			}
		}
	}

	#ifdef STAT
	std::cout << "bubble_bug_sort.stepStat: " << step_stat << std::endl;
	std::cout << "bubble_bug_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}