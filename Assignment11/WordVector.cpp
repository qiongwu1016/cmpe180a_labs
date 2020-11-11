#include <vector>
#include <iterator>
#include "Word.h"
#include "TimedContainer.h"
#include "WordVector.h"

using namespace std;

int WordVector::get_count(const string text) const {
	vector<Word>::const_iterator it = begin();
	while (it != end()) {
		if (it->get_text() ==  text)
			return it->get_count();
		it++;
	}
	return 0;
}



void WordVector::insert(const string text) {
	steady_clock::time_point start_time = steady_clock::now();
	const Word word(text);

	vector<Word>::iterator it = begin();
	while (it != end() && it->get_text() <= text) {
		if (it->get_text() == text) {
			it->increment_count();
			return;
		}
		it++;
	}
	vector<Word>::insert(it, word);

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}

vector<Word>::iterator WordVector::search(const string text) {
	steady_clock::time_point start_time = steady_clock::now();
	int pivot, left = 0, right = size() - 1;
	while (left <= right) {
		pivot = left + (right - left) / 2;
		if (text == (*this)[pivot].get_text()) {
			steady_clock::time_point end_time = steady_clock::now();
			increment_elapsed_time(start_time, end_time);
			return begin() + pivot;
		}

		if (text < (*this)[pivot].get_text())
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
	return end();
}

