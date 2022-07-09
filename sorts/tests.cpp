#include <iostream>
#include <array>

#include "compare.hpp"

/*
	Used to display count of replacements
*/
// #define STAT

/*
	SORTS
*/
#include "bubble.hpp"
#include "bubble_bug.hpp"


template <typename T>
bool compare_arrays(T* array1, T* array2, size_t length) {
	for (size_t i = 0; i < length; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
void display_array(T* array, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


void test1();
void test2();


int main() {
	test1();
}

void test1() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	bubble_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test1.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;


	a = {4, 2, 7, 3, 8, 3, 0, -5};

	bubble_bug_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test1.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2() {
	/*
		Strange behavior:
		if `int answer[]` declaration will be before declaration of array `std::array<int, length> a` => test not passed
		else => passed
	*/
	int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	bubble_bug_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test2.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}
