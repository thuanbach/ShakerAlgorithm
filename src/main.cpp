/*
 * main.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: thuanbachvan
 */


#include <iostream>
#include "shaker_sort.h"

using namespace std;


int* initiate_array(const unsigned int size) {
	int* arr = new int[size];


	for (unsigned int i=0; i< size; i++){
		arr[i] = 20- i;
	}

	return arr;
}

int main(){

	const unsigned int size = 10;

	int* arr = initiate_array(size);

	shaker_sort(arr, size);

	return 0;
}
