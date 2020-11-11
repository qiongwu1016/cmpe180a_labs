#include <iostream>
#include <list>
#include <iterator>
#include "Word.h"
#include "WordList.h"
#include "TimedContainer.h"

using namespace std;

int WordList::get_count(const string text) {
	list<Word>::const_iterator it = begin();
	while (it != end()) {
		if (it->get_text() == text)
			return it->get_count();

		it++;
	}
	//if (it == end())
		return 0;
}

void WordList::insert(const string text) {
	bool word_found = false;
	steady_clock::time_point start_time = steady_clock::now();
	list<Word>::iterator it = begin();
	Word word(text);
	if (size() == 0)
		list<Word>::insert(it, word);
	else {
		it = begin();
		while (it != end() && it->get_text() <= text && word_found == false) {
			if (it->get_text() == text) {
				it->increment_count();
				word_found = true;
			}
			it++;
		}

		if (it == end() && word_found == false)
			push_back(word);
		if (it != end() && word_found == false)
			list<Word>::insert(it, word);
	}
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}



list<Word>::iterator WordList::search(const string text) {
	steady_clock::time_point start_time = steady_clock::now();
	list<Word>::iterator it = begin();
	while (it != end()) {
		if (it->get_text() == text) {
			steady_clock::time_point end_time = steady_clock::now();
			increment_elapsed_time(start_time, end_time);
			return it;
		}
		it++;
	}
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
	return end();
}
