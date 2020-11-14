#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    /**
     * Default constructor.
     */
    Element() : value(0) {}

    /**
     * Constructor.
     * @param val the element's value.
     */
    Element(long val) : value(val) {}

    /**
     * Copy constructor.
     * @param other the other element to be copied.
     */
    Element(const Element& other)
    {
        value = other.value;
        copy_count++;
    }

    /**
     * Destructor.
     */
    virtual ~Element()
    {
        destructor_count++;
    }

    /**
     * Getter.
     * @return the value.
     */
    long get_value() const { return value; }

    /**
     * Getter.
     * @return the value of the global copy_count.
     */
    static long get_copy_count() { return copy_count; }

    /**
     * Getter.
     * @return the value of the global destructor_count.
     */
    static long get_destructor_count() { return destructor_count; }

    /**
     * Reset the values of the global counters.
     */
    static void reset()
    {
        copy_count = destructor_count = 0;
    }

    /**
     * Overloaded == operator.
     * @param elmt1 the first element
     * @param elmt2 the second element
     * @return true if the values of two elements are equal, else false.
     */
    friend bool operator ==(const Element& elmt1, const Element& elmt2);

    /**
     * Overloaded < operator.
     * @param elmt1 the first element
     * @param elmt2 the second element
     * @return true if the value the first element is less than
     *              the value of the second element, else false.
     */
    friend bool operator <(const Element& elmt1, const Element& elmt2);

    /**
     * Overloaded > operator.
     * @param elmt1 the first element
     * @param elmt2 the second element
     * @return true if the value the first element is greater than
     *              the value of the second element, else false.
     */
    friend bool operator >(const Element& elmt1, const Element& elmt2);

    /**
     * Overloaded << operator.
     * @param ostream the output stream.
     * @param elmt the element to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const Element& elmt);

private:
    long value;

    // Static member variables, which are global to the class.
    // These variables exist independently from any Element objects.
    static long copy_count;
    static long destructor_count;
};

#endif /* DATA_H_ */
