#include <iostream>
#include <array>

#include "compare.hpp"

/*
	Used to display count of replacements
*/
#define STAT

/*
	SORTS
*/
#include "bubble.hpp"
#include "bubble_bug.hpp"
#include "bubble_comb.hpp"


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


void bug_test_bubble_bug();

// Test 1
void test1_bubble();
void test1_bubble_bug();
void test1_bubble_comb();

// Test 2
void test2_bubble();
void test2_bubble_bug();
void test2_bubble_comb();

// Test 3
void test3_bubble();
void test3_bubble_bug();
void test3_bubble_comb();


int main() {
	test1_bubble();
	test1_bubble_bug();
	test1_bubble_comb();
	std::cout << std::endl;

	test2_bubble();
	test2_bubble_bug();
	test2_bubble_comb();
	std::cout << std::endl;

	test3_bubble();
	test3_bubble_bug();
	test3_bubble_comb();
	std::cout << std::endl;
}


void bug_test_bubble_bug() {
	/*
		Strange behavior:
		if `const int answer[]` declaration will be before declaration of array `std::array<int, length> a` => test not passed
		else => passed
	*/
	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	bubble_bug_sort<int>(a.data(), length, &compare);

	std::cout
		<< "BugTest.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

/*
	Test 1
*/
void test1_bubble() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	bubble_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test1.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_bubble_bug() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	bubble_bug_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test1.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_bubble_comb() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	bubble_comb_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test1.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

/*
	Test 2
*/
void test2_bubble() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	bubble_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test2.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_bubble_bug() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	bubble_bug_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test2.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_bubble_comb() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	bubble_comb_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test2.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

/*
	Test 3
*/
void test3_bubble() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	bubble_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test3.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_bubble_bug() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	bubble_bug_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test3.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_bubble_comb() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	bubble_comb_sort<int>(a.data(), length, &compare);

	std::cout
		<< "Test3.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}