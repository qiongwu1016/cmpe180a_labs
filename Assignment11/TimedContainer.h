#ifndef TIMEDCONTAINER_H_
#define TIMEDCONTAINER_H_

#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Base class for an STL container that provides
 * an elapsed microsecond timer.
 */
class TimedContainer
{
public:
    /**
     * Default constructor.
     */
    TimedContainer() : elapsed_time(0) {}

    /**
     * Destructor.
     */
    virtual ~TimedContainer() {}

    /**
     * Getter.
     * @return the elapsed time.
     */
    long get_elapsed_time() const { return elapsed_time; }

    /**
     * Reset the elapsed time to 0.
     */
    void reset_elapsed_time() { elapsed_time = 0; }

protected:
    /**
     * Increment the elapsed time.
     * @param start_time the starting time.
     * @param end_time the ending time.
     */
    void increment_elapsed_time(const steady_clock::time_point start_time,
                                const steady_clock::time_point end_time)
    {
        long usec = duration_cast<microseconds>(end_time - start_time).count();
        elapsed_time += usec;
    }

private:
    long elapsed_time;  // the elapsed time
};

#endif /* TIMEDCONTAINER_H_ */
