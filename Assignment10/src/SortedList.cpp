#include <iostream>
#include <iterator>
#include <list>
#include "Node.h"
#include "SortedList.h"

using namespace std;

SortedList::SortedList() {
	Node::reset();
}

SortedList::~SortedList() {
	Node::reset();
}

void SortedList::prepend(const long value) {
	push_front(value);
}

void SortedList::append(long int value) {
	push_back(value);
}

void SortedList::insert(const long value) {
	Node node(value);
	bool original_reversed = false;
	if (check_reversed() == true && size() > 1) {
		original_reversed = true;
		reverse();
	}
	list<Node>::const_iterator it = begin();
	if (it->get_value() >= value) {
		push_front(node);
	} else {
		while ((it != end()) && (*it <= node))
			it++;

		if (it == end())
			push_back(node);
		else
			list<Node>::insert(it, node);

	}
	if (original_reversed == true)
		reverse();
}

void SortedList::remove(int index) {
	list<Node>::const_iterator it = begin();
	for (int i= 0; i < index; i++) it++;
	erase(it);
}

void SortedList::reverse() {
	if (size() > 1) {
		list<Node>::const_iterator it = begin();
		it++;
		while (it != end()) {
			list<Node>::push_front(*it);
			erase(it);
			it++;
		}
	}
}



bool SortedList::check() const {
	if (size() == 0)
		return true;

	list<Node>::const_iterator it = begin();
	list<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is greater than or equal the previous node.
	while ((it != end()) && (*it >= *prev)) {
		prev = it;
		it++;
	}

	return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const {
	if (size() == 0)
		return true;

	list<Node>::const_iterator it = begin();
	list<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is less than or equal to the previous node.
	while ((it != end()) && (*it <= *prev)) {
		prev = it;
		it++;
	}

	return it == end();  // Good if reached the end.
}

Node& SortedList::operator[](const int index) {
	int size = list<Node>::size();
	list<Node>::const_iterator it;

	if (index < size / 2) {
		it = begin();
		for (int i = 0; i < index; i++)
			it++;
	} else {
		it = end();
		for (int i = 0; i < size - index; i++)
			it--;
	}
	return const_cast<Node&>(*it);

}

