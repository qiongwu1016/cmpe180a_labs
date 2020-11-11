#include <map>
#include <iterator>
#include "WordMap.h"
#include "TimedContainer.h"
#include "Word.h"

using namespace std;


int WordMap::get_count(const string text) const {
	return find(text)->second.get_count();
}

void WordMap::insert(const string text) {
	steady_clock::time_point start_time = steady_clock::now();
	Word word(text);
	map<string, Word>::iterator it;
	it = find(text);
	if (it != end())
		it->second.increment_count();
	else {
		map<string, Word>::insert(pair<string, Word>(text, word));
	}

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}


map<string, Word>::iterator WordMap::search(const string text) {
	steady_clock::time_point start_time = steady_clock::now();
	map<string, Word>::iterator it = find(text);
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
	return it;

}
