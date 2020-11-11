#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include "SortedVector.h"
#include "SortedList.h"

/**
 * Test function: Insert new nodes at the beginning of the vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_prepends(SortedVector& sv, const int size);

/**
 * Test function: Insert new nodes at the beginning of the list.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_prepends(SortedList& sl, const int size);

/**
 * Test function: Append new nodes at the end of the vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_appends(SortedVector& sv, const int size);

/**
 * Test function: Append new nodes at the end of the list.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_appends(SortedList& sl, const int size);

/**
 * Test function: Access nodes in the vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 * @throw an exception if anything goes wrong.
 */
void vector_gets(SortedVector& sv, const int size) throw(string);

/**
 * Test function: Access nodes in the list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 * @throw an exception if anything goes wrong.
 */
void list_gets(SortedList& sl, const int size) throw(string);

/**
 * Test function: Insert random values into the sorted vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 * @throw an exception if anything goes wrong.
 */
void vector_inserts(SortedVector& sv, const int size) throw(string);

/**
 * Test function: Insert random values into the sorted list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 * @throw an exception if anything goes wrong.
 */
void list_inserts(SortedList& sl, const int size) throw(string);

/**
 * Test function: Delete all the nodes from the vector
 *                one at a time.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_removes(SortedVector& sv, const int size);

/**
 * Test function: Remove all the nodes from the list
 *                one at a time.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_removes(SortedList& sl, const int size);

/**
 * Test function: Reverse in place the order of the nodes in the vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 * @throw an exception if anything goes wrong.
 */
void vector_reverse(SortedVector& sv, const int size) throw(string);

/**
 * Test function: Reverse in place the order of the nodes in the list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 * @throw an exception if anything goes wrong.
 */
void list_reverse(SortedList& sl, const int size) throw(string);

#endif /* TESTSUITE_H_ */
