#ifndef TIMER_H_
#define TIMER_H_

#include <string>
#include <chrono>
#include "SortedVector.h"
#include "SortedList.h"

using namespace std;
using namespace std::chrono;

class Timer
{
public:
    /**
     * Time a call to function f with no parameters.
     * @param f the function.
     * @throw the error message string if function f throws an exception
     * @return the execution time in milliseconds.
     */
    static long time_it(void f()) throw(string);

    /**
     * Time a call to function f with arguments sorted vector sv and int size.
     * @param sv the sorted vector.
     * @param size the size.
     * @param f the function.
     * @throw the error message string if function f throws an exception
     * @return the execution time in milliseconds.
     */
    static long time_it(SortedVector& sv, const int size,
                        void f(SortedVector&, const int)) throw(string);

    /**
     * Time a call to function f with arguments sorted list sl and int size.
     * @param sv the sorted list.
     * @param size the size.
     * @param f the function.
     * @throw the error message string if function f throws an exception
     * @return the execution time in milliseconds.
     */
    static long time_it(SortedList& sl, const int size,
                        void f(SortedList&, const int)) throw(string);
};

#endif /* TIMER_H_ */
