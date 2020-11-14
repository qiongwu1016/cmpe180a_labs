#include "Sorter.h"
#include "Element.h"

using namespace std;

bool Sorter::sort() throw (string)
{
    move_count = 0;
    compare_count = 0;
    Element::reset();

    start_timer();

    // Sort the data according to the algorithm
    // that is defined by the sorting subclasses.
    run_sort_algorithm();

    stop_timer();
    return is_data_sorted();
}
