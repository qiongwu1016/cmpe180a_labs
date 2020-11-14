#ifndef DATASORTED_H_
#define DATASORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for already sorted data.
 */
class DataSorted: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataSorted() : DataGenerator("Already sorted") {}

    /**
     * Destructor.
     */
    virtual ~DataSorted() {}

    /**
     * Generate already sorted values (low to high) to fill a vector.
     * @param data the data vector to fill.
     */
    void generate_data(vector<Element>& data, int size)
    {
        for (long i = 0; i < size; i++) data.push_back(Element(i));
    }
};

#endif /* DATASORTED_H_ */
