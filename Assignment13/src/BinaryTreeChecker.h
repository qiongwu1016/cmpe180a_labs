/**
 * A binary tree checker for those of us who are paranoid
 * about getting binary trees correct. It maintains a running
 * copy of a tree's node data in set elements. A tree node
 * addition has a corresponding set element addition. A tree node
 * deletion has a corresponding set element deletion. The tree
 * node data is compared to the set elements. Both the tree node
 * data and the set elements can be printed to verify they match.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#ifndef BINARY_TREE_CHECKER_H
#define BINARY_TREE_CHECKER_H

#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

class BinaryTreeChecker
{
public:
    static const int NO_ERROR          =  0;
    static const int DATA_MISMATCH     = -1;
    static const int INSUFFICIENT_DATA = -2;
    static const int REMAINING_DATA    = -3;

    /**
     * Default constructor.
     */
    BinaryTreeChecker(BinarySearchTree& tree) : tree(tree)
    {
        data.reserve(50);
    }

    /**
     * Destructor.
     */
    virtual ~BinaryTreeChecker() {}

    /**
     * Add a tree node's data item to the cache.
     * @param data the data item to add.
     */
    void add(const int data) { cache.insert(data);  }

    /**
     * Remove a data item from the cache.
     * @param data the data item to remove.
     */
    void remove(const int data) { cache.erase(data);  }

    /**
     * Check the tree's current data items against the cache.
     * @param dump true to dump the data items in the tree and in the cache.
     * @return a status code.
     */
    int check(const bool dump);

private:
    BinarySearchTree& tree;  // the tree to check
    set<int> cache;          // the cache of data items
    vector<int> data;        // the tree's data items from an inorder walk

    /**
     * Do an inorder walk of the tree to collect its data items.
     * @param node the root node of the subtree to walk (initially the tree root).
     */
    void walk(BinaryNode *node);

    /**
     * Compare the tree's data items against the data items in the cache.
     * @return a status code.
     */
    int compare(const bool dump) const;
};

#endif // BINARY_TREE_CHECKER_H
