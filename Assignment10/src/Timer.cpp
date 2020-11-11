#include <chrono>
#include "Timer.h"
using namespace std;
using namespace std::chrono;

long Timer::time_it(void f()) throw (string) {
	steady_clock::time_point start_time = steady_clock::now();
	try {
		f();
	} catch (...) {
		throw;
	}
	steady_clock::time_point end_time = steady_clock::now();
	long duration = duration_cast<milliseconds>(end_time - start_time).count();
	return duration;

}


long Timer::time_it(SortedVector& sv, const int size, void f(SortedVector&, const int)) throw(string) {
	steady_clock::time_point start_time = steady_clock::now();
		try {
			f(sv, size);
		} catch (...) {
			throw;
		}
		steady_clock::time_point end_time = steady_clock::now();
		long duration = duration_cast<milliseconds>(end_time - start_time).count(); // @suppress("Method cannot be resolved")
			return duration;
}

long Timer::time_it(SortedList& sl, const int size, void f(SortedList&, const int)) throw(string) {
	steady_clock::time_point start_time = steady_clock::now();
			try {
				f(sl, size);
			} catch (...) {
				throw;
			}
			steady_clock::time_point end_time = steady_clock::now();
			milliseconds ms = duration_cast<milliseconds>(end_time - start_time);
			long duration = ms.count();
			return duration;
}
