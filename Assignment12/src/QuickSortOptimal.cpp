#include "QuickSortOptimal.h"

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
	if (right - left <= 1) return data[left];

	Element middle = data[(right - left) / 2];


	compare_count++;
	if ((data[left] < middle || data[left] == middle)
			&& (data[left] > data[right] || data[left] == data[right])) {
		return data[left];
	}

	compare_count++;
	if ((data[left] > middle || data[left] == middle)
			&& (data[left] < data[right] || data[left] == data[right])) {
		return data[left];
	}

	compare_count++;
	if ((data[left] < middle || data[left] == middle)
			&& (middle < data[right] || middle == data[right])) {
		swap(left, (right - left) /2);
		return data[left];
	}

	compare_count++;
	if ((data[left] > middle || data[left] == middle)
			&& (middle > data[right] || middle == data[right])) {
		swap(left, (right - left) / 2);
		return data[left];
	}

	swap(left, right);
	return(data[left]);
}
