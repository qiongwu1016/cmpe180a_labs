#ifndef DATARANDOM_H_
#define DATARANDOM_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for unsorted random data.
 */
class DataRandom: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataRandom() : DataGenerator("Unsorted random") {}

    /**
     * Destructor.
     */
    virtual ~DataRandom() {}

    /**
     * Generate random values to fill a data vector.
     * Reuse previously generated data if possible.
     * @param data the target data vector.
     * @param size the number of random data elements to generate.
     */
    void generate_data(vector<Element>& data, int size);

private:
    vector<Element> random_data;
};

#endif /* DATARANDOM_H_ */
