#include "ShellSortSuboptimal.h"

void ShellSortSuboptimal::run_sort_algorithm() throw (string) {
	int gap = size/2; //initial gap is half size of the vector.

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
		gap = gap / 2; // half the gap for subsequent pass
	}
}
