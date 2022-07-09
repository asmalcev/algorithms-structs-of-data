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

	int di;
	bool wasReplace;

	for (size_t j = 0; j < length - 1; j++) {
		di = 1;
		wasReplace = false;
		for (size_t i = 0; i < length - 1 - j; i += di) {

			#ifdef STAT
			step_stat++;
			#endif

			if (di > 0) {
				if (compare(array[i], array[i + 1])) {
					T tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;

					wasReplace = true;

					#ifdef STAT
					replace_stat++;
					#endif

					if (i > 1) {
						di = -1;
					}
				}
			} else {
				if (compare(array[i], array[i + 1])) {
					T tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;

					wasReplace = true;

					#ifdef STAT
					replace_stat++;
					#endif

				} else if (i < length - 1) {
					di = 1;
				}

				if (i == 0) {
					di = 1;
				}
			}

			// std::cout
			// 	<< "Iter: " << j << " Elements compare: " << array[i] << " " << array[i + 1]
			// 	<< " i: " << i << " di: " << di << std::endl;
			// for (size_t i = 0; i < length; i++) {
			// 	std::cout << array[i] << " ";
			// }
			// std::cout << std::endl << std::endl;
		}

		if (!wasReplace) {
			break;
		}
	}

	#ifdef STAT
	std::cout << "bubble_bug_sort.stepStat: " << step_stat << std::endl;
	std::cout << "bubble_bug_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}