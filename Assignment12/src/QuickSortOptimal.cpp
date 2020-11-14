#include "QuickSortOptimal.h"

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
	if (right - left <= 1) return data[left];
	int middle = (right - left) / 2;

	compare_count++;
	if (data[middle] > data[left]) {
		compare_count++;
		if (data[right] > data[middle]) {
			swap(middle, left);
			return data[left];
		}
		compare_count++;
		if (data[right] < data[left])
			return data[left];
		swap(right, left);
		return data[left];
	}
	compare_count++;
	if (data[right] > data[left]) {
		return data[left];
	}
	compare_count++;
	if (data[right] < data[middle]) {
		swap(middle, left);
		return data[left];
	}
	swap(right, left);
	return data[left];
}
