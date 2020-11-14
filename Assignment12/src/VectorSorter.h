#ifndef VECTORSORTER_H_
#define VECTORSORTER_H_

#include <string>
#include <vector>
#include "Sorter.h"
#include "Element.h"
using namespace std;

/**
 * Abstract base class of the vector sorting subclasses.
 */
class VectorSorter: public Sorter
{
public:
    /**
     * Constructor.
     * @param name name of the sorting algorithm.
     */
    VectorSorter(string name) : Sorter(name) {}

    /**
     * Destructor.
     */
    virtual ~VectorSorter() {}

    /**
     * Generate the data to sort. The data can be random,
     * already sorted, sorted in reverse, or all zeros.
     * @param generator the data generator.
     * @param size the number of data elements.
     */
    virtual void generate_data(DataGenerator *generator, int size);

    /**
     * Clear the data.
     */
    void clear_data();

    /**
     * Print the data elements.
     */
    void print_data() const;

protected:
    vector<Element> data;  // the vector to sort

    /**
     * Verify that the data is correctly sorted.
     * @return true if correctly sorted, else false.
     */
    bool is_data_sorted() const;

    /**
     * Exchange the values of two data elements.
     * Counts as two moves.
     */
    void swap(const int index1, const int index2);
};

#endif /* VECTORSORTER_H_ */
