/*
 * shaker_sort_measurement.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: thuanbachvan
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iomanip>

#include <algorithm>
#include <chrono>


using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

/**
 * Declare a thousand separator
 */
const string THOUDSAND_SEPARATOR = ",";


int* initiate(const unsigned int size) {
	int* arr = new int[size];


	for (unsigned int i=0; i< size; i++){
		arr[i] = 1000%i;
	}

	return arr;
}

int measure_shaker_sort(int arr[], unsigned int size) {

	auto t1 = chrono::high_resolution_clock::now();

	sort(arr, arr + size);

	auto t2 = chrono::high_resolution_clock::now();

	auto ms_int = duration_cast<milliseconds>(t2 - t1);

	//return ms_int.count();

	return 1;
}


/**
 * Format a number with a thousand separator
 *
 * @param n	An unsigned integer
 * @return A string presents the number with a thousand separator
 */
string format_number(unsigned int n) {

	string s = to_string(n);

	int index = s.length() - 3;

	while (index > 0) {
		s.insert(index, THOUDSAND_SEPARATOR);
		index -= 3;
	}

	return s;
}


void print_exectution_time_to_console(int acending_time, int descending_time, unsigned int array_size){
	const char PLUS_CHARACTER = '+';
		const char TABLE_HORIZONTAL_BORDER_CHARACTER = '-';

		const char TABLE_VERTICAL_BORDER_CHARACTER = '|';

		const unsigned int ARRAY_HEADER_WIDTH = 10;
		const unsigned int ARRAY_HEADER_PADDING = 2;

		const string COLUMN_HEADER = "Array";

		const char BLANK_CHARACTER = ' ';

		const unsigned int FIRST_COLUMN_WIDTH = 20;

		const unsigned int SECOND_COLUMN_WIDTH = 20;

		const unsigned int COLUMN_WIDTH_PER_ARRAY = 11;

		const unsigned int TOTAL_TABLE_WIDTH = FIRST_COLUMN_WIDTH + SECOND_COLUMN_WIDTH;

		// Print a line to indicate size of arrays
		//	cout << "n=" << format_number(n) << endl;

		// Print table header border
		cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
				<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
				<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

		// Print row header
		cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH)
				<< BLANK_CHARACTER << setw(SECOND_COLUMN_WIDTH) << TABLE_VERTICAL_BORDER_CHARACTER << endl;

		// Close table header with a border
		cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
				<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
				<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

		cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH)
							<< left;

		cout << "Random time (ms)";
		// Print execution time for each array ordering.
//		for (unsigned int i = 0; i < NUMBER_OF_ARRAY_ORDERING; i++) {
//			cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH)
//					<< left;
//
//			if (i == 0) {
//				cout << "Random time (ms)";
//			} else if (i == 1) {
//				cout << "Ordered time (ms)";
//			} else {
//				cout << "Reverse time (ms)";
//			}
//
//			for (unsigned int k = 0; k < NUMBER_OF_ARRAYS_PER_SIZE; k++) {
//				cout << TABLE_VERTICAL_BORDER_CHARACTER << right
//						<< setw(ARRAY_HEADER_WIDTH) << execution_time[i][k];
//			}
//			cout << TABLE_VERTICAL_BORDER_CHARACTER << endl;
//		}

		// Close the table with a border
		cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
				<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
				<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;
}

void measure_shaker_sort_efficiency() {
	unsigned int size;

	cout << "Input size of the array (0 to exit) >";
	cin >> size;

	int* array = initiate(size);


	sort(array, array + size);

	unsigned int acending_time = measure_shaker_sort(array, size);


	// reverse the array
	reverse(array, array + size);

	unsigned int descending_time = measure_shaker_sort(array, size);

}
