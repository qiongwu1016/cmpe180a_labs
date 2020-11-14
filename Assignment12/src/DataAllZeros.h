#ifndef DATAALLZEROS_H_
#define DATAALLZEROS_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for data that is all zeros.
 */
class DataAllZeros: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataAllZeros() : DataGenerator("All zeroes") {}

    /**
     * Destructor.
     */
    virtual ~DataAllZeros() {}

    /**
     * Generate all zeros to fill a data vector.
     * @param data the data vector to fill.
     */
    void generate_data(vector<Element>& data, int size)
    {
        for (int i = 0; i < size; i++) data.push_back(Element(0));
    }
};

#endif /* DATAALLZEROS_H_ */
