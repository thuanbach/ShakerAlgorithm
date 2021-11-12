/**
 * Implement the Shaker sort.
 *
 * @file	shaker_sort.h
 * @author	Thuan Bach
 * @date	November 3, 2021
 *
 */
#ifndef SRC_SHAKER_SORT_H_
#define SRC_SHAKER_SORT_H_

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
void shaker_sort(int arr[], const unsigned int size);

#endif /* SRC_SHAKER_SORT_H_ */
