#ifndef LISTSORTER_H_
#define LISTSORTER_H_

#include <string>
#include "Sorter.h"
#include "LinkedList.h"

/**
 * Abstract base class of the singly linked list sorting algorithms.
 */
class ListSorter: public Sorter
{
public:
    /**
     * Constructor.
     * @param name name of the sorting algorithm.
     */
    ListSorter(string name) : Sorter(name) {}

    /**
     * Destructor.
     */
    virtual ~ListSorter() {}

    /**
     * Generate the data to sort. The data can be random,
     * already sorted, sorted in reverse, or all zeros.
     * @param generator the data generator.
     * @param size the number of data elements.
     */
    virtual void generate_data(DataGenerator *generator, int size);

    /**
     * Print the data elements.
     */
    void print_data() const;

    /**
     * Clear the data.
     */
    void clear_data();

protected:
    LinkedList data;  // the data to sort

    /**
     * Verify that the data is correctly sorted.
     * @return true if correctly sorted, else false.
     */
    bool is_data_sorted() const;
};

#endif /* LISTSORTER_H_ */
