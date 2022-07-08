#pragma once

template <typename T>
T* bubble_sort(T* array, size_t length, bool (*compare)(T, T)) {
	bool wasReplace = false;

	for (size_t i = 0; i < length - 1; i++) {
		wasReplace = false;

		for (size_t j = 0; j < length - i - 1; j++) {
			if (compare(array[j], array[j + 1])) {
				T tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				wasReplace = true;
			}
		}

		if (!wasReplace) {
			break;
		}
	}

	return array;
}