#include "ShellSortOptimal.h"

void ShellSortOptimal::run_sort_algorithm() throw (string) {

	//find the initial gap
	int gap = 1;
	while (gap < size / 3) {
		gap = gap * 3 + 1;
	}

	while (gap >= 1) { //quit the loop when sort with gap = 1 is done.
			for (int i = gap; i < size; i++) {
				int j = i;
				compare_count++;
				while (j >= gap && data[j] < data[j - gap]) {
					swap(j, j - gap); //swap with a bigger element which at a gap distance. until the gap distance element is smaller.
					move_count = move_count + 2;
					j = j - gap;
				}
			}
			gap = (gap - 1) / 3; // half the gap for subsequent pass
		}

}
