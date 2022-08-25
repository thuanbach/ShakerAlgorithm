/**
 * This file contains the main function where the main application gets started.
 *
 * @file main.cpp
 * @author Thuan Bach
 * @date	November 3, 2021
 */

#include <iostream>
#include "shaker_sort_measurement.h"
#include "shaker_sort_test.h"

/** Define a test mode used to run unit tests */
const unsigned int TEST_MODE = 1;

/**  Define an application mode used to run the Shaker sort' measurement */
const unsigned int APP_MODE = 2;

/**  Define a running mode for the application. */
const unsigned int RUNNING_MODE = APP_MODE;

/**
 * The main function where the Shaker Sort Measurement starts execution.
 * @param	N/A
 * @return 	Always 0 if the application terminated correctly.
 */
int main() {

	if (RUNNING_MODE == APP_MODE) {
		measure_shaker_sort_efficiency();
	} else {
		test_shaker_sort();
	}

	return 0;
}
