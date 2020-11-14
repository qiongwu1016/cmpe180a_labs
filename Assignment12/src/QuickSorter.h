#ifndef QUICKSORTER_H_
#define QUICKSORTER_H_

#include <string>
#include "VectorSorter.h"
#include "Element.h"

/**
 * The abstract base class of the quicksort algorithms.
 */
class QuickSorter: public VectorSorter
{
public:
    /**
     * Constructor.
     * @param name the name of this sorting algorithm.
     */
    QuickSorter(string name) : VectorSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~QuickSorter() {}

    /**
     * Run the quicksort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm() throw (string);

protected:
    /**
     * Choose a pivot strategy. Implemented by the quicksort subclasses.
     * @param left the left index of the subrange to sort.
     * @param right the right index of the subrange to sort.
     * @return the chosen pivot value.
     */
    virtual Element& choose_pivot_strategy(const int left, const int right) = 0;

private:
    /**
     * The quicksort algorithm recursively sorts data subranges.
     * @param left the left index of the subrange to sort.
     * @param right the right index of the subrange to sort.
     */
    void quicksort(const int left, const int right);

    /**
     * Partition the subrange by moving data elements < pivot to the left
     * and data elements > pivot to the right.
     * @param left the left index of the partition to sort.
     * @param right the right index of the partition to sort.
     * @param pivot the pivot value.
     */
int partition(const int left, const int right, const Element& pivot);

    /**
     * Choose the pivot according to a pivot strategy.
     * The chosen pivot will be moved temporarily to the right end.
     * @param left the left index of the partition to sort.
     * @param right the right index of the partition to sort.
     * @return the pivot value.
     */
    Element& choose_pivot(const int left, const int right);
};

#endif /* QUICKSORTER_H_ */
