#ifndef NODE_H_
#define NODE_H_
using namespace std;

/**
 * A node for the sorted vector and sorted linked list.
 */
class Node
{
public:

	/**
     * Constructor.
     * Globally count how many times a constructor is called.
     * @param the_value the initial value.
     */
	Node(const long the_value);

    /**
     * Copy constructor.
     * Globally count how many times a copy constructor is called.
     * @param other the other node object to copy.
     */
    Node(const Node& other);

    /**
     * Overloaded assignment operator.
     * Globally count how many times an assignment operator is called.
     * @param rhs the right-hand-side node object.
     */
    Node& operator =(const Node& rhs);

    /**
     * Destructor.
     * Globally count how many times a destructor is called.
     */
    virtual ~Node();

    /**
     * Getter.
     * @return the value.
     */
    long get_value() const;

    /**
     * Getter.
     * @return the value of the global constructor_count.
     */
    static long get_constructor_count();

    /**
     * Getter.
     * @return the value of the global copy_count.
     */
    static long get_copy_count();

    /**
     * Getter.
     * @return the value of the global assign_count.
     */
    static long get_assign_count();

    /**
     * Getter.
     * @return the value of the global destructor_count.
     */
    static long get_destructor_count();

    /**
     * Reset the values of the global counters.
     */
    static void reset();

    /**
     * Overloaded == operator.
     * @return true if the values of two nodes are equal, else false.
     */
    bool operator ==(const Node& other) const;

    /**
     * Overloaded <= operator.
     * @return true if the value of this node is less than or equal to
     *              the value of the other node, else false.
     */
    bool operator <=(const Node& other) const;

    /**
     * Overloaded >= operator.
     * @return true if the value of this node is greater than or equal to
     *              the value of the other node, else false.
     */
    bool operator >=(const Node& other) const;

private:
    long value;

    // Static member variables, which are global to the class.
    // These variables exist independently from any Node objects.
    static long constructor_count;
    static long copy_count;
    static long assign_count;
    static long destructor_count;
};

#endif /* NODE_H_ */
