#include <iostream>
#include "AvlTree.h"

using namespace std;

int AvlTree::height(const BinaryNode *ptr) const
{
    return BinarySearchTree::height(ptr);
}

void AvlTree::insert(const int data)
{
	steady_clock::time_point start_time = steady_clock::now();

	insert(data, this->root);

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{
	probe_counts++;
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

//reference: https://stackoverflow.com/questions/4219743/balancing-an-avl-tree-c
BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    if (ptr == nullptr) return ptr;

    if (height (ptr-> left) - height(ptr->right) > 1)
    {
        if (height(ptr->left->left) >= height(ptr->left->right))
        {
            ptr = single_right_rotation(ptr);
            //cout << "Single right rotation at " << ptr -> data << endl;
        }
        else
        {
            ptr = double_left_right_rotation(ptr);
            //cout << "Double left-right rotation at " << ptr->data << endl;
        }
    }
    else if (height (ptr->right) - height (ptr->left) > 1)
    {
        if (height (ptr->right->right) >= height(ptr->right->left))
        {
            ptr = single_left_rotation(ptr);
            //cout << "Single left rotation at node at " << ptr->data << endl;
        }
        else
        {
            ptr = double_right_left_rotation(ptr);
            //cout << "Double right-left rotation at " << ptr->data << endl;
        }
    }
    // Recompute the node's height.
    ptr->height = max(height(ptr->left), height(ptr->right)) +1;

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}


//reference: https://stackoverflow.com/questions/4219743/balancing-an-avl-tree-c
BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{

    BinaryNode *k1;
    k1 = k2 -> left; //set k1 the left child of k2
    k2 -> left = k1 -> right; //set the right child of k2 as left child of k1
    k1 -> right = k2; //set k2 the right child of k1
    k2 -> height = max(height(k2 -> right), height(k2 -> left)) + 1; //maintain the height of k2
    return k1;

}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{

    BinaryNode *k2;
    k2 = k1 -> right; // set k2 the right child of k1
    k1 -> right = k2 -> left; //set k2's left child as k1's right child
    k2 -> left = k1; // set k1 as k2's left child
    k1 -> height = max(height (k1-> left), height(k1-> right)) + 1; //maintain the height of k1

    return k2;

}

BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
    //do left rotation at k2's left child
    k3 -> left = single_left_rotation(k3->left);
    //do right rotation at k3
    return single_right_rotation(k3);

}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
    //do right rotation at k1's right child
    k1 -> right = single_right_rotation(k1->right);
    //do left rotation at k1
    return single_left_rotation(k1);

}


int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
