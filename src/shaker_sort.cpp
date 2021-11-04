/*
 * shaker_sort.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include <string>

using namespace std;

void print_araray(int *array, int size) {

	cout << "[";

	for (int i = 0; i < size; i++) {
		cout << array[i] << ",";
	}

	cout << "]";
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void shaker_sort(int *arr, const unsigned int size) {

	unsigned int left_direction_count = 0;
	unsigned int right_direction_count = 0;

	for (unsigned int i = 0; i < size - 1; i++) {

		if (i % 2 == 0) {

			for (unsigned int j = left_direction_count;
					j < size - right_direction_count - 1; j++) {

				if (arr[j] > arr[j + 1]) {

					swap(arr[j], arr[j + 1]);
				}
			}

			left_direction_count++;

		} else {

			for (unsigned int j = size - 1 - right_direction_count;
					j > left_direction_count - 1; j--) {

				if (arr[j - 1] > arr[j]) {

					swap(arr[j - 1], arr[j]);
				}

			}

			right_direction_count++;
		}

		cout << "Pass " << to_string(i);

		print_araray(arr, size);

		cout << endl << endl;
	}
}
