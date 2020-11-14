#ifndef SHELLSORTOPTIMAL_H_
#define SHELLSORTOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the optimal shellsort algorithm
 * for a vector of data, where the diminishing increment is
 * calculated according to Don Knuth.
 */
class ShellSortOptimal: public VectorSorter
{
public:
    /**
     * Constructor.
     * @param name the name of this sorting algorithm.
     */
    ShellSortOptimal(string name) :VectorSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~ShellSortOptimal() {}

    /**
     * Run the optimal shellsort algorithm.
     * According to Don Knuth:
     * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SHELLSORTOPTIMAL_H_ */
