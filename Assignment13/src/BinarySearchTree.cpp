#include <string>
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int BinarySearchTree::height(const BinaryNode *ptr) const
{
    //Reference: https://www.techiedelight.com/calculate-height-binary-tree-iterative-recursive/
    if (ptr == nullptr) return -1; //base case
    else return (1 + max(height(ptr-> left), height (ptr-> right)));

}

BinarySearchTree::~BinarySearchTree() {
	delete_tree(root);
}

void BinarySearchTree::delete_tree(BinaryNode *ptr) {
	if (ptr == nullptr) return;
	delete_tree(ptr->left);
	delete_tree(ptr->right);
	delete ptr;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr)
{
	comparison_counts++;
    if (ptr->left == nullptr) return (ptr);
    else return find_min(ptr->left);
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr)
{
	comparison_counts++;
	if (ptr->right == nullptr) return ptr;
    else return find_max(ptr->right);
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr)
{
	if (ptr == nullptr)
		return false;
	comparison_counts++;
	if (ptr->data == data)
		return true;
	if (data < ptr->data)
		return contains(data, ptr->left);//search for left subtree
	else
		return contains(data, ptr->right);//search for right subtree
}

void BinarySearchTree::insert(const int data) {
	steady_clock::time_point start_time = steady_clock::now();
	insert(data, root);
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(start_time, end_time);
}

void BinarySearchTree::insert(const int data, BinaryNode *&ptr) {
	probe_counts++;
	//if the data already exist,  no need to insert.
	if (contains(data, ptr))
		return;

	//Create a new node only when a null link is encountered.
	if (ptr == nullptr) {
		ptr = new BinaryNode(data);
	}


	//if the data is smaller than the current node, then insert to left.
	//else if the data is bigger than the current node, then insert to right.
	comparison_counts++;
	if (ptr->data > data) insert(data, ptr->left);
	else if (ptr->data < data) insert(data, ptr->right);
}

void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{


	    if (ptr == nullptr) return; // data not exist

	    if (ptr->data == data) //found data node
	    {
	        //node has no children
	        if (ptr -> right == nullptr && ptr -> left == nullptr)
	        {
	        	delete ptr;
	        	ptr = nullptr;
	        }
	        //node has 2 Children
	        else if (ptr -> right != nullptr && ptr-> left != nullptr) {
	        	//copy minimum to current node
	        	ptr->data = find_min(ptr->right)->data;

	        	remove(ptr->data, ptr->right);//remove the minimum from the subtree
	        }
	        else {
	            //node has 1 child
	            BinaryNode *temp = ptr;
	            if (ptr -> left == nullptr)
	                ptr = ptr->right;
	            else
	                ptr = ptr -> left;
	            delete temp;
	        }
	    } else if (ptr->data > data) remove(data, ptr->left);
	    else if (ptr->data < data) remove(data, ptr->right);

}
