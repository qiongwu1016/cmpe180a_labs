#include <iostream>
#include "Element.h"

using namespace std;

// Static member variables, which are global to the class.
long Element::copy_count;
long Element::destructor_count;

bool operator ==(const Element& elmt1, const Element& elmt2)
{
    return elmt1.value == elmt2.value;
}

bool operator <(const Element& elmt1, const Element& elmt2)
{
    return elmt1.value < elmt2.value;
}

bool operator >(const Element& elmt1, const Element& elmt2)
{
    return elmt1.value > elmt2.value;
}

ostream& operator <<(ostream& outs, const Element& elmt)
{
    outs << elmt.get_value();
    return outs;
}
