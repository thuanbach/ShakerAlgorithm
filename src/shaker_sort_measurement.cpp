/**
 *
 * This module is used to support user interaction in selecting sizes of arrays to measure the Shaker sorts' efficiency.
 *
 * @file	shaker_sort_measurement.cpp
 * @author	Thuan Bach
 * @date	November 3, 2021
 *
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iomanip>

#include <algorithm>
#include <chrono>
#include "shaker_sort.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;
using std::chrono::time_point;

/**
 * Declare the stream size limit
 */
const long STREAM_SIZE_LIMIT = std::numeric_limits<std::streamsize>::max();

/**
 * Declare a thousand separator
 */
const string THOUDSAND_SEPARATOR = ",";

/**
 * Initiate an array with random values.
 * @param	size	The size of the array.
 * @return	The array with the size provided and items of value initiated by the rand() method from algorithm library.
 */

int* initiate(const unsigned int size) {
	int *arr = new int[size];

	for (unsigned int i = 0; i < size; i++) {
		arr[i] = rand();
	}

	return arr;
}

/**
 * Measure shaker sort's execution time.
 *
 * @param	arr	The array needs to be sorted.
 * @param	size	The size of the array.
 * @return	The shaker sort's execution time in nanosecond.
 */
int measure_shaker_sort(int arr[], const unsigned int size) {

	auto t1 = chrono::high_resolution_clock::now();

	shaker_sort(arr, size);

	auto t2 = chrono::high_resolution_clock::now();

	nanoseconds ms_int = duration_cast<nanoseconds>(t2 - t1); // @suppress("Invalid arguments")

	return ms_int.count();
}

/**
 * Format a number with a thousand separator.
 *
 * @param n	An unsigned integer need to be formated.
 * @return A string presents the number with a thousand separator.
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

/**
 * Print the Shaker sort's execution times to console in the table format.
 * @param	ascending_time	The shaker sort's execution time for the ascending array.
 * @param	descending_time	The shaker sort's execution item for the descending array.
 * @return	N/A
 */
void print_exectution_time_to_console(unsigned int ascending_time,
		unsigned int descending_time, unsigned int array_size) {
	const char PLUS_CHARACTER = '+';

	const char TABLE_HORIZONTAL_BORDER_CHARACTER = '-';

	const char TABLE_VERTICAL_BORDER_CHARACTER = '|';

	const char BLANK_CHARACTER = ' ';

	const unsigned int FIRST_COLUMN_WIDTH = 20;

	const unsigned int SECOND_COLUMN_WIDTH = 20;

	const unsigned int TOTAL_TABLE_WIDTH = FIRST_COLUMN_WIDTH
			+ SECOND_COLUMN_WIDTH + 1;

	// Print a line to indicate size of arrays
	cout << endl;
	cout << "n=" << format_number(array_size) << endl;

	// Close table header with a border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH) << left
			<< "Ascending time (ns)" << TABLE_VERTICAL_BORDER_CHARACTER << right
			<< setw(SECOND_COLUMN_WIDTH) << ascending_time
			<< TABLE_VERTICAL_BORDER_CHARACTER << endl;

	cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH) << left
			<< "Descending time (ns)" << TABLE_VERTICAL_BORDER_CHARACTER
			<< right << setw(SECOND_COLUMN_WIDTH) << descending_time
			<< TABLE_VERTICAL_BORDER_CHARACTER << endl;

	// Close the table with a border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	cout << endl;
}

/**
 * Parse users' input from the Console, and check the data before return it as a integer value.
 *
 * @param  N/A
 * @return An integer that the user inputs
 */

int get_user_input_as_number() {
	int number;

	while (true) {

		cin >> number;

		if (cin.fail() || number < 0) {
			cin.clear();
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			cout << "ERROR: Incorrect number. Please input again." << endl;
			cout << ">";
			continue;
		}

		// ignore character return for the next input
		cin.ignore(STREAM_SIZE_LIMIT, '\n');

		break;
	}

	return number;
}

/**
 *
 * <p> Prompt users for inputing the array size, then initiate array data. </p>
 * <p> Finally measure the Shaker sort's execution time and print result to the console.</p>
 * <p> It will continues the above process until users choose the option that exits the application.</p>
 *
 * @param	N/A
 * @return	N/A
 *
 */
void measure_shaker_sort_efficiency() {

	cout << "Start Shaker Sort's Measurement Application" << endl;
	while (true) {
		unsigned int size = 0;

		cout << "Input size of the array (0 to exit) >";
		size = get_user_input_as_number();

		if (size == 0) {
			cout << "Application shutdown";
			break;
		}

		int *array = initiate(size);

		//sort the array
		sort(array, array + size);

		unsigned int ascending_time = measure_shaker_sort(array, size);

		// reverse the array
		reverse(array, array + size);

		unsigned int descending_time = measure_shaker_sort(array, size);

		print_exectution_time_to_console(ascending_time, descending_time, size);
	}
}
