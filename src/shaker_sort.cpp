/*
 * shaker_sort.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include <string>

using namespace std;

void print_array(int array[], int size) {

	cout << "[";

	for (int i = 0; i < size; i++) {
		cout << array[i] << ",";
	}

	cout << "]";
}

void print_pass(int pass, int array[], unsigned int size){
	cout << "Pass " << to_string(pass);

	print_array(array, size);

	cout << endl << endl;
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void shaker_sort(int arr[], const unsigned int size) {

	unsigned int left_direction_index = 0;
	unsigned int right_direction_index = 0;

	for (unsigned int i = 0; i < size - 1; i++) {

		if (i % 2 == 0) {

			for (unsigned int j = left_direction_index;
					j < size - 1 - right_direction_index; j++) {

				if (arr[j] > arr[j + 1]) {

					swap(arr[j], arr[j + 1]);
				}
			}

			left_direction_index++;

		} else {

			for (unsigned int j = size - 1 - right_direction_index;
					j > left_direction_index - 1; j--) {

				if (arr[j - 1] > arr[j]) {

					swap(arr[j - 1], arr[j]);
				}

			}

			right_direction_index++;
		}

		// print_pass(i, arr, size);
	}
}
