#include <iostream>
#include "QuickSorter.h"
#include <iostream>
using namespace std;

void QuickSorter::run_sort_algorithm() throw (string)
{

    quicksort(0, size-1);

}

void QuickSorter::quicksort(const int left, const int right)
{
    // Continue the recursive calls until the indexes cross.
    if (left <= right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements <  pivot
        quicksort(p+1, right); // Sort elements >= pivot
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{


	int i = left;
    for (int j = left + 1; j <= right; j++){
    	compare_count++;
    	if (data[j] < pivot) {
    		i++;
    		if (i != j) swap(i, j);
    	}
    }
    swap(left, i);
    return i;
}


