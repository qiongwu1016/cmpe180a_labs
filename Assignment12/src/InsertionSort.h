
#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include "VectorSorter.h"

/**
 * The class that implements the insertion sort algorithm
 * for a vector of data.
 */
class InsertionSort: public VectorSorter
{
public:
    /**
     * Constructor.
     * @param name the name of the sorting algorithm.
     */
    InsertionSort(string name) : VectorSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~InsertionSort() {}

    /**
     * Run the insertion sort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm() throw (string);
};

#endif /* INSERTIONSORT_H_ */
