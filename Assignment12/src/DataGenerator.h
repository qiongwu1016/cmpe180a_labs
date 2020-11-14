#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <string>
#include <vector>
#include "Element.h"

using namespace std;

/**
 * Abstract base class of the data generator subclasses.
 */
class DataGenerator
{
public:
    /**
     * Constructor.
     * @param name the name of this generator.
     */
    DataGenerator(string name) : name(name) {}

    /**
     * Destructor.
     */
    virtual ~DataGenerator() {}

    /**
     * Getter
     * @return the name of this generator.
     */
    string get_name() const { return name; }

    /**
     * Generate the data. Implemented by the generator subclasses.
     * @param data the generated data.
     * @param size the size of the data.
     */
    virtual void generate_data(vector<Element>& data, int size) = 0;

private:
    string name;
};

#endif /* DATAGENERATOR_H_ */
