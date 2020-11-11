#include "SortedVector.h"
#include "Node.h"
#include <iostream>

using namespace std;

SortedVector::SortedVector() {
	Node::reset();
}

SortedVector::~SortedVector() {
	Node::reset();
}

void SortedVector::prepend(const long value) {
	Node node(value);
	vector<Node>::const_iterator it;
	it = begin();
	vector<Node>::insert(it, node);
}

void SortedVector::append(const long value) {
	Node node(value);
	push_back(node);
}

void SortedVector::insert(const long value) {
	if (size() == 0)
		append(value); //append the node with assigned value in an empty vector
	else if (check() or check_reversed()) {
		bool original_reversed = false;

		/*
		 * check the vector is sorted or reversed sorted. if reversed, reverse the vector first, then insert node with the value
		 */
		if (check_reversed() && size() > 1) {
			original_reversed = true;
			reverse();
		}

		/*
		 * insert value into the sorted vector
		 */
		vector::const_iterator it;
		it = begin();
		Node node(value);
		if (value <= it->get_value())
			prepend(value);  //insert at the beginning
		else {
			while (it != end() && (*it) <= node)
				it++;
			if (it == end())
				append(value);//insert at the end
			else
				vector<Node>::insert(it, node);//insert in the middle
		}

		/*
		 * if the vector is original reversed, after insertion, reverse the vector back.
		 */
		if (original_reversed == true)
			reverse();
	}
}

void SortedVector::remove(const int index) {
	vector::const_iterator it;
	it = begin();
	for (int i = 0; i < index; i++) it++;
	erase(it);
}

void SortedVector::reverse() {
	vector::const_iterator it;
	it = begin();
	it++;
	while (it != end()) {
		vector<Node>::insert(begin(), *it);
		it++;
		if (it != end()) erase(it);
	}
}

bool SortedVector::check() const {
	if (size() == 0)
		return true;
	vector::const_iterator it = begin();
	vector::const_iterator prev = it;
	it++;

	while( it != end() && *it >= *prev) {
		prev = it;
		it ++;
	}

	if (it == end())
		return true;
	else
		return false;

}

bool SortedVector::check_reversed() const {
	if (size() == 0)
		return true;
	vector::const_iterator it = begin();
	vector::const_iterator prev = it;
	it++;
	while (it != end() && *it <= *prev) {
		prev = it;
		it++;
	}
	if (it == end())
		return true;
	else
		return false;

}
