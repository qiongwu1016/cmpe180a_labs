/**
 * An implementation of the binary search tree and its operations.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 *
 * Modified from Data Structures and Algorithm Analysis in C++, 4th ed.
 * by Mark Allen Weiss
 * Pearson, 2014
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include "BinaryNode.h"
#include "TimedContainer.h"

using namespace std;

class BinarySearchTree : public TimedContainer
{
public:

	long probe_counts;
	long comparison_counts;

    /**
     * Default constructor
     */
    BinarySearchTree() : probe_counts(0), comparison_counts(0), root(nullptr) {}

    /**
     * Destructor
     */
    ~BinarySearchTree();

    void delete_tree(BinaryNode *ptr);

    /**
     * Getter.
     * @return pointer to the root of the tree.
     */
    BinaryNode *get_root() const { return root; }

    /**
     * Public getter.
     * @return the height of the tree.
     */
    int height() const { return height(root); }

    /**
     * Find the minimum data value in the tree.
     * @return the minimum data value.
     * @throw an error message if the tree is empty.
     */
    int find_min() throw(string)
    {
        if (is_empty()) throw(string("Empty tree"));
        return find_min(root)->data;
    }

    /**
     * Find the maximum data value in the tree.
     * @return the maximum data value.
     * @throw an error message if the tree is empty.
     */
    int find_max() throw(string)
    {
        if (is_empty()) throw(string("Empty tree"));
        return find_max(root)->data;
    }

    /**
     * Is the tree empty?
     * @return true if and only if the tree is empty.
     */
    bool is_empty() const { return root == nullptr; }

    /**
     * Search for a data value in the tree.
     * @param data the data to search for.
     * @return true if and only if data is in the tree.
     */
    bool contains(const int data) { return contains(data, root); }

    /**
     * Insert a data value into the tree
     * and set the new root of the tree.
     * @param data the data to insert.
     */
    void insert(const int data);

    /**
     * Remove a data value from the tree
     * and set the new root of the tree.
     * Do nothing if the data value is not found.
     * @param data the data to remove.
     */
    void remove(const int data) { remove(data, root);  }

protected:
    /**
     * Compute the height of a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return the height.
     */
    virtual int height(const BinaryNode *ptr) const;

    /**
     * Insert a data value into a subtree
     * and set the new root of the subtree.
     * @param data the data to insert.
     * @param ptr pointer to the root node of the subtree.
     */
    virtual void insert(const int data, BinaryNode* &ptr);

    /**
     * Protected method to remove a data value from a subtree
     * and set the new root of the subtree.
     * Do nothing if the data item is not found.
     * @param data the data to remove.
     * @param ptr pointer to the root node of the subtree.
     */
    virtual void remove(const int data, BinaryNode* &ptr);

    BinaryNode *root;

private:

    /**
     * Find the minimum data value in a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return pointer to the node containing the smallest data value
     *         or nullptr if the subtree is empty.
     */
    BinaryNode *find_min(BinaryNode *ptr);

    /**
     * Find the maximum data value in a subtree.
     * @param ptr pointer to the root node of the subtree.
     * @return pointer to the node containing the largest data value
     *         or nullptr if the subtree is empty.
     */
    BinaryNode *find_max(BinaryNode *ptr);

    /**
     * Search for a data value in a subtree.
     * @param data the data to search for.
     * @param ptr pointer to the root node of the subtree.
     * @return true if and only if data is in the subtree.
     */
    bool contains(const int data, BinaryNode *ptr);
};


#endif // BINARY_SEARCH_TREE_H
