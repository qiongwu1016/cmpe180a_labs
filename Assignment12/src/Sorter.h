#ifndef SORTER_H_
#define SORTER_H_

#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include "DataGenerator.h"

using namespace std;
using namespace std::chrono;

/**
 * The abstract base class of the sorting algorithms.
 */
class Sorter
{
public:
    /**
     * Constructor.
     * @param name the name of the sorting algorithm.
     */
    Sorter(string name)
        : size(0), move_count(0), compare_count(0), name(name), elapsed_time(0) {}

    /**
     * Destructor.
     */
    virtual ~Sorter() {}

    // Name of the sorting algorithm.
    string get_name() const { return name; }

    /**
     * Get the data size.
     * @return the size.
     */
    int get_size() const { return size; }

    /**
     * Set the data size.
     * @param sz the size to set.
     */
    void set_size(int sz) { size = sz; }

    /**
     * Get the number of moves during a sort.
     * @return the number of moves.
     */
    long get_move_count() const { return move_count; }

    /**
     * Get the number of compares during a sort.
     * @return the number of compares.
     */
    long get_compare_count() const { return compare_count; }

    /**
     * @return the element copy count.
     */
    long get_copy_count() const { return Element::get_copy_count(); }

    /**
     * @return the element destructor count.
     */
    long get_destructor_count() const { return Element::get_destructor_count(); }

    /**
     * Get the elapsed time in milliseconds.
     * @return the elapsed time.
     */
    long get_elapsed_ms() const { return elapsed_time; }

    /**
     * Abstract function to generate the data to sort.
     * @param generator the generator function.
     * @param size the number of data elements.
     */
    virtual void generate_data(DataGenerator *generator, int size) = 0;

    /**
     * Abstract function to clear the data to sort.
     */
    virtual void clear_data() = 0;

    /**
     * Abstract functino to print the data. Useful for debugging.
     */
    virtual void print_data() const = 0;

    /**
     * Sort the data by invoking the sorting algorithm.
     * Count the number of data element moves and compares.
     * Calculate the elapsed time in milliseconds.
     * @throws an exception if an error occurred.
     */
    virtual bool sort() throw (string);

protected:
    int size;            // number of data elements to sort
    long move_count;     // count of data element moves during a sort
    long compare_count;  // count of data element compares during a sort

    /**
     * Abstract function to run a sorting algorithm.
     */
    virtual void run_sort_algorithm() throw (string) = 0;

    /**
     * Abstract function to check if the data is sorted.
     * @return true if sorted, else false.
     */
    virtual bool is_data_sorted() const = 0;

private:
    string name;
    steady_clock::time_point timer;
    long elapsed_time;

    /**
     * Start the timer before beginning a sort.
     */
    void start_timer() { timer = steady_clock::now(); }

    /**
     * Stop the timer after the sort finishes
     * and compute the elapsed time.
     */
    void stop_timer()
    {
        auto now = steady_clock::now();
        elapsed_time = duration_cast<milliseconds>(now - timer).count();
    }
};

#endif /* SORTER_H_ */
