/**
 * Implement the Shaker sort.
 *
 * @file	shaker_sort.cpp
 * @author	Thuan Bach
 * @date	November 3, 2021
 *
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Declare a debug mode to test each pass of the shaker sort.
 */
const bool DEBUG = false;

/**
 * Print the array to the console.
 * It supports for testing.
 *
 * @param	array	The array needs to be printed out.
 * @param	size	The size of the array.
 * @return	N/A
 */
void print_array(int array[], int size) {

	cout << "[";

	for (int i = 0; i < size; i++) {
		cout << array[i];

		if (i < size - 1) {
			cout << ",";
		}
	}

	cout << "]";
}

/**
 * Print values of the array to console at the pass index of the sort.
 * It supports for testing.
 *
 * @param	pass	The pass index of the sort.
 * @param	array	The array needs to be print out.
 * @param	size	The size of the array.
 * @return	N/A
 *
 */
void print_pass(int pass, int array[], unsigned int size) {
	cout << "Pass " << to_string(pass);

	print_array(array, size);

	cout << endl << endl;
}

/**
 * Swap the value of x and y together.
 *
 * @param x	The first value to be swapped.
 * @param y The second value to be swapped.
 * @return N/A
 */
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

/**
 * <p> Implement the Shaker sort that is a modified of the bubble sort. </p>
 * <p> Instead of shift biggest items to to the end of the array for each loop, it shifts the biggest item to end for the first pass.</p>
 * <p> And for the second pass, it shifts the smallest item to the start of the array.</p>
 * <p> And repeats the process with both directions until the array is sorted.</p>
 *
 * @param arr[]	The array needs to be sorted.
 * @param size	The size of the array.
 * @return	N/A
 */
void shaker_sort(int arr[], const unsigned int size) {
	if (size < 1) {
		return;
	}

	unsigned int left_direction_index = 0;
	unsigned int right_direction_index = 0;

	for (unsigned int i = 0; i < size - 1; i++) {
		bool exchanged = false;

		if (i % 2 == 0) {

			for (unsigned int j = left_direction_index;
					j < size - 1 - right_direction_index; j++) {

				if (arr[j] > arr[j + 1]) {
					exchanged = true;
					swap(arr[j], arr[j + 1]);
				}
			}

			left_direction_index++;

		} else {

			for (unsigned int j = size - 1 - right_direction_index;
					j > left_direction_index - 1; j--) {

				if (arr[j - 1] > arr[j]) {
					exchanged = true;
					swap(arr[j - 1], arr[j]);
				}
			}

			right_direction_index++;
		}

		// Support for testing purpose.
		if (DEBUG) {
			print_pass(i, arr, size);
		}

		if (!exchanged) {
			// the array is already sorted
			break;
		}
	}
}
