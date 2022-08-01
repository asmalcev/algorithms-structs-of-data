#pragma once

#ifdef STAT
#include <iostream>
#endif

template <typename T>
class Heap {
private:
	#ifdef STAT
	size_t step_stat = 0;
	size_t replace_stat = 0;
	#endif

	size_t length;
	size_t capacity;
	T * array;

	void heapify(size_t i) {
		int j;
		while (2 * i + 1 < length) {
			#ifdef STAT
			step_stat++;
			#endif
			j = i;

			if (array[2 * i + 1] > array[i]) {
				j = 2 * i + 1;
			}

			if (2 * i + 2 < length && array[2 * i + 2] > array[j]) {
				j = 2 * i + 2;
			}

			if (i == j) {
				break;
			}

			#ifdef STAT
			replace_stat++;
			#endif

			std::swap(array[i], array[j]);
			i = j;
		}
	}

public:

	Heap(size_t capacity, T * array)
		: length(0), capacity(capacity), array(array) {}

	~Heap() {}

	T get_min() {
		if (length == 0) {
			throw std::out_of_range("Heap is empty");
		}
		if (length == 1) {
			return array[--length];
		}

		T root = array[0];
		array[0] = array[--length];
		heapify(0);
		return root;
	}

	void insert(T value) {
		if (length == capacity) {
			throw std::out_of_range("Heap is full");
		}

		length++;
		size_t i = length - 1;
		array[i] = value;

		while (i != 0 && array[i] > array[(i - 1) / 2]) {
			#ifdef STAT
			step_stat++;
			replace_stat++;
			#endif

			std::swap(array[i], array[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	#ifdef STAT
	void print_stat() {
		std::cout << "shaker_sort.stepStat: " << step_stat << std::endl;
		std::cout << "shaker_sort.replaceCount: " << replace_stat << std::endl;
	}
	#endif

};
