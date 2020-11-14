#ifndef DATAREVERSESORTED_H_
#define DATAREVERSESORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for reverse-sorted data.
 */
class DataReverseSorted: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataReverseSorted() : DataGenerator("Reverse sorted") {}

    /**
     * Destructor.
     */
    virtual ~DataReverseSorted() {}

    /**
     * Generate reverse sorted values (high to low) to fill a data vector.
     * @param data the data vector to fill.
     */
    virtual void generate_data(vector<Element>& data, int size)
    {
        for (long i = 0; i < size; i++) data.push_back(Element(size - i));
    }
};

#endif /* DATAREVERSESORTED_H_ */
