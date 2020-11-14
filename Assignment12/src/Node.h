#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    /**
     * Default constructor.
     */
    Node() : next(nullptr) {}

    /**
     * Constructor.
     * @param elmt the element contained in this node.
     */
    Node(const Element elmt) : element(elmt), next(nullptr) {}

    /**
     * Destructor.
     */
    virtual ~Node() {};

    Element element;
    Node *next;
};

#endif /* NODE_H_ */
