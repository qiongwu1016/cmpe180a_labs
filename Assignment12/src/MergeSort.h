#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <string>
#include "LinkedList.h"
#include "ListSorter.h"

/**
 * The class that implements the mergesort algorithm
 * for a singly linked list of data.
 */
class MergeSort: public ListSorter
{
public:
    /**
     * Constructor.
     * @param name the name of the sorting algorithm.
     */
    MergeSort(string name) : ListSorter(name) {}

    /**
     * Destructor.
     */
    virtual ~MergeSort() {}

    /**
     * Run the mergesort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm() throw (string);

private:
    /**
     * The mergesort algorithm recursively splits and merges data lists.
     * @param list the list of data to sort.
     */
    void mergesort(LinkedList& list);

    /**
     * Merge two sublists back into a single list.
     * @param list the merged list.
     * @param sublist1 the first sublist.
     * @param sublist2 the second sublist.
     */
    void merge(LinkedList& list, LinkedList& sublist1, LinkedList& sublist2);

    /**
     * Clear the data.
     */
    void clear();
};

#endif /* MERGESORT_H_ */
