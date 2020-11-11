#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "Timer.h"
#include "Node.h"
#include "SortedVector.h"
#include "SortedList.h"
#include "TestSuite.h"

using namespace std;

/**
 * Run the test suite.
 * @throw an exception if anything goes wrong.
 */
void run_test_suite() throw(string);

/**
 * Run and time a pair of vector and linked list test functions.
 * @param test_name the name of the test pair.
 * @param fv the vector function.
 * @param fl the linked list function.
 * @throw an exception if anything goes wrong.
 */
void run_test_functions(const string test_name,
                        void fv(SortedVector& sv, const int size),
                        void fl(SortedList& sl,   const int size))
    throw(string);

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n);

/**
 * Vector and list sizes.
 */
const int SIZES[] = {100, 500, 1000, 5000, 10000};

/**
 * The main.
 * Run the test suite and catch any exceptions.
 *
 *
 */
int main()
{
    long et;
    srand(time(NULL));

    // Run the test suite. Catch any exceptions.
    try
    {
        et = Timer::time_it(run_test_suite);
    }
    catch (string& msg)
    {
        cout << endl << "***** " << msg << endl;
        cout.flush();
        return -1;
    }

    cout << "Done! Total time: " << et/1000.0 << " seconds" << endl;
    return 0;
}

void run_test_suite() throw(string)
{
    run_test_functions("Prepend", vector_prepends, list_prepends);

    run_test_functions("Append", vector_appends, list_appends);

    run_test_functions("Get", vector_gets, list_gets);

    run_test_functions("Remove", vector_removes, list_removes);

    run_test_functions("Insert", vector_inserts, list_inserts);

    run_test_functions("Reverse", vector_reverse, list_reverse);
}

void run_test_functions(const string test_name,
		void fv(SortedVector &sv, const int size),
		void fl(SortedList &sl, const int size)) throw (string) {
	// Print a nice header for the test pair.
	for (int i = 0; i < test_name.length(); i++)
		cout << "=";
	cout << endl << test_name << endl;
	for (int i = 0; i < test_name.length(); i++)
		cout << "=";
	cout << endl;
	    cout << "        |--------------------Vector-------------------|";
	    cout <<       "  |---------------------List--------------------|" << endl;
	    cout << "  Size      Time  Creates   Copies     Assigns Destroys";
	    cout <<       "      Time  Creates   Copies     Assigns Destroys" << endl;

	// Loop over the data sizes for the tests.
	for (int size : SIZES) {
		cout << setw(6) << commafy(size);

		// Run and time the vector test and print its statistics.
		SortedVector sv;
		long etv = Timer::time_it(sv, size, fv);
		cout << setw(7) << commafy(etv) << " ms";
		cout << setw(9) << commafy(Node::get_constructor_count());
		cout << setw(9) << commafy(Node::get_copy_count());
		cout << setw(12) << commafy(Node::get_assign_count());
		cout << setw(9) << commafy(Node::get_destructor_count());
		cout.flush();

		// Run and time the linked list test and print its statistics.
		SortedList sl;
		long etl = Timer::time_it(sl, size, fl);
		cout << setw(7) << commafy(etl) << " ms";
		cout << setw(9) << commafy(Node::get_constructor_count());
		cout << setw(9) << commafy(Node::get_copy_count());
		cout << setw(12) << commafy(Node::get_assign_count());
		cout << setw(9) << commafy(Node::get_destructor_count());
		cout.flush();

		cout <<endl;
		}

	cout << endl;
}

string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}






