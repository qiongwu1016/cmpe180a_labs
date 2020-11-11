#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <list>
#include <iterator>
#include "Node.h"

using namespace std;

/***** Modify this file if necessary. *****/

/**
 * A sorted linked list of Node objects.
 */
class SortedList : public list<Node>
{
public:
    /**
     * Defaut constructor.
     * Reset the global Node counters.
     */
    SortedList();

    /**
     * Destructor.
     * Reset the global Node counters.
     */
    virtual ~SortedList();

    /**
     * Insert a new node at the beginning of the list.
     * @param value the new node's value.
     */
    void prepend(const long value);

    /**
     * Append a new node at the end of the list.
     * @param value the new node's value.
     */
    void append(const long value);

    /**
     * Insert a new node into the list at the
     * appropriate position to keep the list sorted.
     * @param value the value of the node to insert.
     */
    void insert(const long value);

    /**
     * Delete a node.
     * @param index the index of the node to remove.
     */
    void remove(const int index);

    /**
     * Reverse in place the order of the nodes of the list.
     */
    void reverse();

    /**
     * Check that the nodes are sorted.
     * @return true if sorted, false if not.
     */
    bool check() const;

    /**
     * Check that the nodes are reverse sorted.
     * @return true if reverse sorted, false if not.
     */
    bool check_reversed() const;

    /**
     * Overloaded [] operator that returns
     * a reference to a Node element.
     * @param index the index of the element to return.
     * @return a reference to the element.
     */
    Node& operator[](const int index);
};

#endif /* SORTEDLIST_H_ */
