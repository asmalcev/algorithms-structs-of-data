#include <iostream>
#include <array>
#include <chrono>

#include "util.hpp"

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
#include "shaker.hpp"
#include "oddeven.hpp"
#include "heap.hpp"


#define mesure_time(x) {                            \
	using std::chrono::high_resolution_clock;         \
	using std::chrono::duration;                      \
	auto t1 = high_resolution_clock::now();           \
	x;                                                \
	auto t2 = high_resolution_clock::now();           \
	duration<double, std::milli> ms_double = t2 - t1; \
	std::cout << ms_double.count() << "ms\n";         \
}



void bug_test_bubble_bug();

// Test 1
void test1_bubble();
void test1_bubble_bug();
void test1_bubble_comb();
void test1_shaker();
void test1_oddeven();
void test1_heap();

// Test 2
void test2_bubble();
void test2_bubble_bug();
void test2_bubble_comb();
void test2_shaker();
void test2_oddeven();
void test2_heap();

// Test 3
void test3_bubble();
void test3_bubble_bug();
void test3_bubble_comb();
void test3_shaker();
void test3_oddeven();
void test3_heap();

// Test 4
void test4_bubble();
void test4_bubble_bug();
void test4_bubble_comb();
void test4_shaker();
void test4_oddeven();
void test4_heap();


int main() {
	test1_bubble();
	test1_bubble_bug();
	test1_bubble_comb();
	test1_shaker();
	test1_oddeven();
	test1_heap();
	std::cout << std::endl;

	test2_bubble();
	test2_bubble_bug();
	test2_bubble_comb();
	test2_shaker();
	test2_oddeven();
	test2_heap();
	std::cout << std::endl;

	test3_bubble();
	test3_bubble_bug();
	test3_bubble_comb();
	test3_shaker();
	test3_oddeven();
	test3_heap();
	std::cout << std::endl;

	test4_bubble();
	test4_bubble_bug();
	test4_bubble_comb();
	test4_shaker();
	test4_oddeven();
	test4_heap();
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

	mesure_time(bubble_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test1.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_bubble_bug() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	mesure_time(bubble_bug_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test1.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_bubble_comb() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	mesure_time(bubble_comb_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test1.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_shaker() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	mesure_time(shaker_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test1.shaker.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_oddeven() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	mesure_time(oddeven_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test1.oddeven.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test1_heap() {
	const size_t length = 8;
	std::array<int, length> a = {4, 2, 7, 3, 8, 3, 0, -5};

	const int answer[] = {-5, 0, 2, 3, 3, 4, 7, 8};

	mesure_time(heap_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test1.heap.result: "
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

	mesure_time(bubble_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test2.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_bubble_bug() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(bubble_bug_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test2.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_bubble_comb() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(bubble_comb_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test2.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_shaker() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(shaker_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test2.shaker.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_oddeven() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(oddeven_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test2.oddeven.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test2_heap() {
	const size_t length = 8;
	std::array<int, length> a = {1, 2, 3, 0, 4, 5, 6, 7};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(heap_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test2.heap.result: "
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

	mesure_time(bubble_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test3.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_bubble_bug() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(bubble_bug_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test3.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_bubble_comb() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(bubble_comb_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test3.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_shaker() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(shaker_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test3.shaker.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_oddeven() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(oddeven_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test3.oddeven.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test3_heap() {
	const size_t length = 8;
	std::array<int, length> a = {7, 6, 5, 4, 3, 2, 1, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7};

	mesure_time(heap_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test3.heap.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

/*
	Test 4
*/
void test4_bubble() {
	const size_t length = 16;
	std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	mesure_time(bubble_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test4.bubble.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test4_bubble_bug() {
	const size_t length = 16;
	std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	mesure_time(bubble_bug_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test4.bubble_bug.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test4_bubble_comb() {
	const size_t length = 16;
	std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	mesure_time(bubble_comb_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test4.bubble_comb.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test4_shaker() {
	const size_t length = 16;
	std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	mesure_time(shaker_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test4.shaker.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test4_oddeven() {
	const size_t length = 16;
	std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	mesure_time(oddeven_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test4.oddeven.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}

void test4_heap() {
	const size_t length = 16;
	std::array<int, length> a = {15, 12, 14, 5, 7, 4, 2, 6, 10, 8, 13, 3, 1, 9, 11, 0};

	const int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	mesure_time(heap_sort<int>(a.data(), length, &compare));

	std::cout
		<< "Test4.heap.result: "
		<< (compare_arrays<int>(a.data(), answer, length) ? "passed" : "not passed")
		<< std::endl;
}