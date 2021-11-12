/**
 * Implement unit tests for the Shaker sort.
 *
 * @file	shaker_sort_test.cpp
 * @author	Thuan Bach
 * @date	November 12, 2021
 *
 */

#include <iostream>
#include <string>
#include "shaker_sort.h"
#include "shaker_sort_test.h"

using namespace std;

/**
 * Verify if the array is sorted.
 *
 * @param	array The array needs to be verified the sort.
 * @param	size  The size of the array.
 * @return	A string represents Pass or Fail.
 */
string verify_array_sorted(int array[], const unsigned int size) {
	string result = "Pass";

	if (size < 1) {
		return result;
	}

	for (unsigned int i = 0; i < size - 1; i++) {
		if (array[i + 1] < array[i]) {
			result = "Fail";
			break;
		}
	}

	return result;
}

/**
 * Test Shaker sort with empty array.
 *
 * @param	N/A
 * @return	N/A
 */
void test_empty_arry() {
	const unsigned int size = 0;

	int arr[] = { };

	shaker_sort(arr, size);

	cout << "Test an empty array: " << verify_array_sorted(arr, 0) << endl;
}

/**
 * Test Shaker sort with array containing one item.
 *
 * @param	N/A
 * @return	N/A
 */

void test_array_with_one_item() {
	const unsigned int size = 1;

	int arr[] = { 1 };

	shaker_sort(arr, size);

	cout << "Test the array with one item: " << verify_array_sorted(arr, size)
			<< endl;
}

/**
 * Test Shaker sort with an ascending array.
 *
 * @param	N/A
 * @return	N/A
 */
void test_ascending_array() {
	const unsigned int size = 10;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	shaker_sort(arr, size);

	cout << "Test the ascending array: " << verify_array_sorted(arr, size)
			<< endl;
}

/**
 * Test Shaker sort with an descending array.
 *
 * @param	N/A
 * @return	N/A
 */
void test_descending_array() {
	const unsigned int size = 10;

	int arr[] = { 10, 9, 8, 6, 7, 5, 4, 3, 2, 1 };

	shaker_sort(arr, size);

	cout << "Test the descending array: " << verify_array_sorted(arr, size)
			<< endl;
}

/**
 * Test Shaker sort with an random array.
 *
 * @param	N/A
 * @return	N/A
 */
void test_random_array() {
	const unsigned int size = 10;

	int arr[] = { 9, 8, 1, 2, 5, 6, 7, 10, 4, 3 };

	shaker_sort(arr, size);

	cout << "Test a random array: " << verify_array_sorted(arr, size) << endl;
}

/**
 * Test Shaker sort with an array with the same items.
 *
 * @param	N/A
 * @return	N/A
 */
void test_array_with_the_same_items() {
	const unsigned int size = 10;

	int arr[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

	shaker_sort(arr, size);

	cout << "Test the array with the same items: "
			<< verify_array_sorted(arr, size);
}

/**
 * Run unit tests for shaker sorts.
 *
 * @param	N/A
 * @return	N/A
 */
void test_shaker_sort() {

	test_empty_arry();

	test_array_with_one_item();

	test_ascending_array();

	test_descending_array();

	test_random_array();

	test_array_with_the_same_items();
}
