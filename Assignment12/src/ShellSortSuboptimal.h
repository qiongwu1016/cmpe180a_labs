#ifndef SHELLSORTSUBOPTIMAL_H_
#define SHELLSORTSUBOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the suboptimal Shellsort algorithm
 * for a vector of data, where the diminishing increment is halved
 * for each pass.
 */
class ShellSortSuboptimal: public VectorSorter
{
public:
    /**
     * Constructor.
     * @param name the name of this algorithm.
     */
    ShellSortSuboptimal(string name) : VectorSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~ShellSortSuboptimal() {}

    /**
     * Run the suboptimal shellsort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SHELLSORTSUBOPTIMAL_H_ */
