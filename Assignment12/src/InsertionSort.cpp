#include "InsertionSort.h"
#include "VectorSorter.h"
#include <iostream>

void InsertionSort::run_sort_algorithm() throw (string) {

	for (int i = 1; i < size; i++) {
		int j = i - 1;
		bool done_insert = false;
		compare_count++;
		if (data[j] > data[i] || data[j] == data[i]) {
			do {
				// ASSERT: 0 <= j <= i - 1
				compare_count++;
				if (data[j] < data[i]) {
					data.insert(data.begin() + j + 1, data[i]);
					move_count = move_count + 1;
					done_insert = true;
					break;
				}
				j--;
			} while (j >= 0);
			if (!done_insert) {
				data.insert(data.begin(), data[i]);
				move_count = move_count + 1;
			}
			data.erase(data.begin() + i + 1);
		}
	}

}
