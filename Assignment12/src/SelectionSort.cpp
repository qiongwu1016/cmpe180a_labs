#include "SelectionSort.h"
#include "VectorSorter.h"
#include "Sorter.h"

void SelectionSort::run_sort_algorithm() throw (string)
{
    int sizem1 = size - 1;

    // For each element of the vector ...
    for (int i = 0; i < sizem1; i++)
    {
        Element smallest = data[i];
        int index_of_smallest = i;

        // ... find the index of the smallest value
        // in the rest of the vector.
        for (int j = i + 1; j < size; j++)
        {
            compare_count++;

            if (data[j] < smallest)
            {
                smallest = data[j];
                index_of_smallest = j;
            }
        }

        // Swap in the smallest value if it isn't already there.
        if (i != index_of_smallest) swap(i, index_of_smallest);
    }
}
