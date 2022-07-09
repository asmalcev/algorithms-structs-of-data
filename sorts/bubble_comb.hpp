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

	bool wasReplace;
	size_t comb = length / 1.247; // magic number for better perfomance

	// for (size_t i = 0; i < length - 1; i++) {
	// 	wasReplace = false;
	// 	std::cout << comb << std::endl;

	// 	for (size_t j = 0; j < length - i - 1; j += comb) {

	// 		#ifdef STAT
	// 		step_stat++;
	// 		#endif

	// 		if (j + comb < length && compare(array[j], array[j + comb])) {
	// 			T tmp = array[j];
	// 			array[j] = array[j + comb];
	// 			array[j + comb] = tmp;

	// 			wasReplace = true;

	// 			#ifdef STAT
	// 			replace_stat++;
	// 			#endif
	// 		}
	// 	}

	// 	if (!wasReplace) {
	// 		break;
	// 	}
	// 	comb /= 1.247;
	// }

	while (comb > 1) {
		for (size_t i = 0, j = comb; j < length; i++, j++) {
			#ifdef STAT
			step_stat++;
			#endif

			if (array[i] > array[j]) {
				T tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;

				#ifdef STAT
				replace_stat++;
				#endif
			}
		}

		comb /= 1.247;
	}

	#ifdef STAT
	std::cout << "bubble_sort.stepStat: " << step_stat << std::endl;
	std::cout << "bubble_sort.replaceCount: " << replace_stat << std::endl;
	#endif

	return array;
}