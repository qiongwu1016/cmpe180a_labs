#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"

/**
 * The linked list class for the mergesort algorithm.
 */
class LinkedList
{
public:
    /**
     * Default constructor.
     */
    LinkedList() : head(nullptr), tail(nullptr), size(0) {};

    /**
     * Constructor: Create a new list from an existing one.
     * Both lists will share the nodes.
     * @param head the head of the existing list.
     * @param tail the tail of the existing list.
     * @param size the size of the existing list.
     */
    LinkedList(Node *head, Node *tail, const int size)
    {
        this->head = head;
        this->tail = tail;
        this->tail->next = nullptr;

        this->size = size;
    }

    /**
     * Destructor.
     */
    virtual ~LinkedList() {}

    /**
     * Get the head of the list.
     * @return the head.
     */
    Node *get_head() const { return head; }

    /**
     * Get the tail of the list.
     * @return the tail.
     */
    Node *get_tail() const { return tail; }

    /**
     * Get the size of the list.
     * @return the size.
     */
    int get_size() const { return size; }

    /**
     * Set the head, tail, and size of the linked list.
     * @param head the head of the linked list.
     * @param tail the tail of the linked list.
     * @param size the size of the linked list.
     */
    void set(Node *head, Node *tail, int size)
    {
        this->head = head;
        this->tail = tail;
        this->tail->next = nullptr;
        this->size = size;
    }

    /**
     * Remove the head of the list and return the removed node.
     * @return the removed node.
     */
    Node *remove_head();

    /**
     * Reset the head, tail, and size of the list.
     */
    void reset()
    {
        head = tail = nullptr;
        size = 0;
    }

    /**
     * Add a node to the tail of the list.
     * @param value the value of the node to add.
     */
    void add(const Element& elmt);

    /**
     * Add a node to the tail of the list.
     * @param node the node to add.
     */
    void add(Node *node);

    /**
     * Delete all the nodes of the list.
     */
    void clear();

    /**
     * Print the values of the list's nodes.
     */
    void print() const;

    /**
     * Split this list into two sublists.
     * @param list1 the first sublist.
     * @param list2 the second sublist.
     */
    void split(LinkedList& list1, LinkedList& list2);

    /**
     * Add another list to the end of this list.
     * @param other_list the other list.
     */
    void concatenate(LinkedList& other_list);

private:
    Node *head;
    Node *tail;
    int size;
};

#endif /* LINKEDLIST_H_ */
