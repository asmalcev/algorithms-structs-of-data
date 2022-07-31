#pragma once

#include <iostream>

bool compare(int a, int b) {
	return a > b;
}

template <typename T>
bool compare_arrays(const T* array1, const T* array2, size_t length) {
	for (size_t i = 0; i < length; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
void display_array(const T* array, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}