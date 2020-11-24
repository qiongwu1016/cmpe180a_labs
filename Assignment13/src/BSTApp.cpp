/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"
#include "TimedContainer.h"

using namespace std;

int main( )
{
	ofstream outs1, outs2, outs3;

	outs1.open("Probes_for_insert.txt");
	outs2.open("Compares_for_insert.txt");
	outs3.open("Elapsed_ms_for_insert.txt");

	int VALUES[50000];
	srand(time(0));

	BinarySearchTree bst;
	AvlTree avlt;
	int size[] = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

	for (int i = 0; i < 50000; i++) {
		VALUES[i] = rand() % 1000000;
		bst.insert(VALUES[i]);
		//cerr << i << " " << bst.probe_counts << endl;

		avlt.insert(VALUES[i]);
		if (i % 1000 == 0) cerr<< i <<endl;

		for (int j = 0; j < 10; j++)
			if (i == size[j]) {

				outs1 << i << "," << bst.probe_counts << ","
						<< avlt.probe_counts << endl;
				outs2 << i << "," << bst.comparison_counts << ","
						<< avlt.comparison_counts << endl;
				outs3 << i << "," << bst.get_elapsed_time() * 1e-6<< ","
						<< avlt.get_elapsed_time() * 1e-6<< endl;
			}
	}

  outs1.close();
  outs2.close();
  outs3.close();
  cout <<"end"<<endl;
}

