#ifndef QUICKSORTSUBOPTIMAL_H_
#define QUICKSORTSUBOPTIMAL_H_

#include "QuickSorter.h"

/**
 * The class that implements the suboptimal quicksort algorithm
 * for a vector of data by using a bad pivot strategy.
 */
class QuickSortSuboptimalRight: public QuickSorter
{
public:
    /**
     * Constructor.
     * @param name the name of this sorting algorithm.
     */
    QuickSortSuboptimalRight(string name) : QuickSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~QuickSortSuboptimalRight() {}

private:
    /**
     * Choose a bad pivot, always the leftmost element of the subrange.
     * @param left the left index of the subrange to sort.
     * @param right the right index of the subrange to sort.
     * @return the chosen pivot value.
     */
    virtual Element& choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTSUBOPTIMAL_H_ */
