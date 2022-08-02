#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
void merge(
	T * array, size_t split, size_t length, bool (*compare)(T, T)
	#ifdef STAT
	, size_t & step_stat,
	size_t & replace_stat
	#endif
) {
	size_t pos1 = 0;
	size_t pos2 = split;
	size_t pos3 = 0;

	T * tmp = new T[length];
	while (pos1 < split && pos2 < length) {
		#ifdef STAT
		step_stat++;
		replace_stat++;
		#endif

		if (compare(array[pos2], array[pos1])) {
			tmp[pos3++] = array[pos1++];
		} else {
			tmp[pos3++] = array[pos2++];
		}
	}

	while (pos2 < length) {
		#ifdef STAT
		step_stat++;
		replace_stat++;
		#endif

		tmp[pos3++] = array[pos2++];
	}

	while (pos1 < split) {
		#ifdef STAT
		step_stat++;
		replace_stat++;
		#endif

		tmp[pos3++] = array[pos1++];
	}

	for (pos3 = 0; pos3 < length; pos3++) {
		#ifdef STAT
		step_stat++;
		replace_stat++;
		#endif

		array[pos3] = tmp[pos3];
	}

	delete[] tmp;
}

template <typename T>
T* merge_sort(
	T* array, size_t length, bool (*compare)(T, T)
	#ifdef STAT
	, size_t & step_stat,
	size_t & replace_stat
	#endif
) {
	size_t split;

	if (length > 1)  {
		split = length / 2;
		merge_sort<T>(array, split, compare, step_stat, replace_stat);
		merge_sort<T>(array + split, length - split, compare, step_stat, replace_stat);
		merge(array, split, length, compare, step_stat, replace_stat);
	}

	return array;
}