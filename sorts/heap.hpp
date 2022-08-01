#pragma once

#include "../structs/heap.hpp"

#ifdef STAT
#include <iostream>
#endif

template <typename T>
T* heap_sort(T* array, size_t length, bool (*compare)(T, T)) {
	Heap<int> heap(length, array);

	for (size_t i = 0; i < length; i++) {
		heap.insert(array[i]);
	}

	for (size_t i = length - 1; i > 0; i--) {
		array[i] = heap.get_min();
	}
	heap.print_stat();

	return array;
}