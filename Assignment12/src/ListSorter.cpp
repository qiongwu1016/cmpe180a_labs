#include <iostream>
#include <vector>
#include "Element.h"
#include "ListSorter.h"

void ListSorter::generate_data(DataGenerator *generator, int size)
{
    clear_data();

    vector<Element> v;
    generator->generate_data(v, size);

    for (int i = 0; i < size; i++) data.add(v[i]);
    set_size(size);
}

void ListSorter::print_data() const
{
    Node *ptr = data.get_head();

    while (ptr != nullptr)
    {
        cout << " " << ptr->element.get_value();
        ptr = ptr->next;
    }

    cout << endl;
}

bool ListSorter::is_data_sorted() const
{
    Node *ptr = data.get_head();

    // Chase next pointers from start to end.
    while ((ptr != nullptr) && (ptr->next != nullptr))
    {
        if (ptr->element.get_value() > ptr->next->element.get_value()) return false;  // incorrect
        ptr = ptr->next;
    }

    return true;  // correct
}

void ListSorter::clear_data()
{
    if (data.get_size() > 0) data.clear();
}
