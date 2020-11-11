#include <string>
#include <stdlib.h>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

void vector_prepends(SortedVector& sv, const int size)
{
    for (int i = size-1; i >= 0; i--) sv.prepend(i);
}

void list_prepends(SortedList& sl, const int size)
{
    for (int i = size-1; i >= 0; i--) sl.prepend(i);
}

void vector_appends(SortedVector& sv, const int size)
{
    for (int i = 0; i < size; i++) sv.append(i);
}

void list_appends(SortedList& sl, const int size)
{
    for (int i = 0; i < size; i++) sl.append(i);
}

void vector_gets(SortedVector& sv, const int size) throw(string)
{
	// First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%(sv.size());
        long value = sv[index].get_value() ;

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

void list_gets(SortedList& sl, const int size) throw(string)
{
    //First fill the list data.
	list_appends(sl, size);
	Node::reset();
	// Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()% (sl.size()) ;
        long value = sl[index].get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}

void vector_inserts(SortedVector& sv, const int size) throw(string)
{
	Node::reset();
	for (int i = 1; i < size; i++)
		sv.insert(rand());
    if (!sv.check()) throw("Vector sort error!");
}

void list_inserts(SortedList& sl, const int size) throw(string)
{
	Node::reset();
	for (int i = 1; i < size; i++)
		sl.insert(rand());
	if (!sl.check())
		throw("List sort error!");
}

void vector_removes(SortedVector& sv, const int size)
{
  // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    while (sv.size() > 0)
    {
        int index = rand()%sv.size();
        sv.remove(index);
    }
}

void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {
        int index = rand()%sl.size();
        sl.remove(index);
    }
}

void vector_reverse(SortedVector& sv, const int size) throw(string)
{
	// first fill the vector data
	vector_appends(sv, size);
	Node::reset();

    // reverse the vector
	sv.reverse();

    if (!sv.check_reversed()) throw("Vector reverse sort error!");
}

void list_reverse(SortedList& sl, const int size) throw(string)
{
	// first fill the list data
	list_appends(sl, size);
	Node::reset();

	//reverse the list
    sl.reverse();
    if (!sl.check_reversed()) throw("List reverse sort error!");
}
