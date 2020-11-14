#include <string>
#include "MergeSort.h"
#include <iostream>

using namespace std;

void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

void MergeSort::mergesort(LinkedList& list)
{
//	cerr << "merge sort list:";
//	list.print();
	if (list.get_size() > 1) {
		LinkedList list1, list2;
		list.split(list1, list2);
//		cerr << "split list1: ";
//		list1.print();
//		cerr << "split list2: ";
//		list2.print();
		mergesort(list1);
		mergesort(list2);
		list.reset();
		merge(list, list1, list2);
	}
//	cerr << "sort result: ";
//	list.print();
}

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
//	cerr << "merge list1: ";
//	sublist1.print();
//	cerr << "merge list2: ";
//	sublist2.print();
	while (sublist1.get_size() > 0 && sublist2.get_size() > 0) {
		compare_count++;
		move_count++;
		if (sublist1.get_head()->element < sublist2.get_head()->element)
			list.add(sublist1.remove_head());
		else
			list.add(sublist2.remove_head());
	}
	if (sublist1.get_size() > 0) {
		list.concatenate(sublist1);
		move_count++;
	}
	if (sublist2.get_size() > 0) {
		list.concatenate(sublist2);
		move_count++;
	}
//	cerr << "merge result: ";
//	list.print();
}

void MergeSort::clear() { data.clear(); }
