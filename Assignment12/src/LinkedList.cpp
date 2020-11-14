#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cerr << " " << ptr->element.get_value();
    }
    cerr << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
	// size == 0
	if (get_size() == 0)
		return;
	// size == 1
	if (get_size() == 1) {
		list1.size = 1;
		list1.head = head;
		list1.tail = tail;
		return;
	}
	// size > 1
	list1.size = get_size() / 2;
	list2.size = get_size() - get_size() / 2;
	list1.head = head;
	// forward the pointer
	Node* p = head;
	for (int i = 0; i < get_size() / 2; i++) {
		list1.tail = p;
		p = p->next;
	}
	list1.tail->next = nullptr;
	list2.head = p;
	list2.tail = tail;
	list2.tail->next = nullptr;
}

void LinkedList::concatenate(LinkedList& other_list)
{
	tail->next = other_list.head;
	tail = other_list.tail;
	size += other_list.size;
}
