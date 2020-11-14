#include <iostream>
#include <ctime>

#include "VectorSorter.h"

void VectorSorter::generate_data(DataGenerator *generator, int size)
{
    clear_data();
    generator->generate_data(data, size);
    set_size(size);
}

void VectorSorter::print_data() const
{
    int size = get_size();
    for (int i = 0; i < size; i++) cout << " " << data[i];

    cout << endl;
}

bool VectorSorter::is_data_sorted() const
{
    int sizem1 = get_size() - 1;
    for (int i = 0; i < sizem1; i++)
    {
        if (data[i] > data[i+1]) return false;  // incorrect
    }

    return true;  // correct
}

void VectorSorter::clear_data()
{
    if (data.size() > 0) data.clear();
}

void VectorSorter::swap(const int index1, const int index2)
{
    Element temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;

    move_count += 2;
}
