#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
void heapify(T* array, size_t length, size_t i, bool (*compare)(T, T)) {
	size_t largest = i;
	size_t l = 2 * i + 1;
	size_t r = 2 * i + 2;

	if (l < length && array[l] > array[largest]) {
		largest = l;
	}

	if (r < length && array[r] > array[largest]) {
		largest = r;
	}

	if (largest != i) {
		std::swap(array[i], array[largest]);
		heapify(array, length, largest, compare);
	}
}

template <typename T>
T* heap_sort(T* array, size_t length, bool (*compare)(T, T)) {
	for (size_t i = length / 2 - 1; i >= 0; i--) {
		heapify(array, length, i, compare);
	}

	for (size_t i = length - 1; i >= 0; i--) {
		std::swap(array[0], array[i]);
		heapify(array, i, 0, compare);
	}

	return array;
}