#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "VectorSorter.h"

/**
 * The class that implements the selection sort algorithm
 * for a vector of data.
 */
class SelectionSort: public VectorSorter
{
public:
    /**
     * Constructor.
     * @param name the name of this sorting algorithm.
     */
    SelectionSort(string name) : VectorSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~SelectionSort() {}

    /**
     * Run the selection sort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SELECTIONSORT_H_ */
