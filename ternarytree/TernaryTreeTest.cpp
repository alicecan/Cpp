/////////////////////////////////////////////////////
// Author: hard worker (github/alicecan)
//
// Description:
//	This program implements a ternary search tree
//  based on the algorithm discussed on dr. cobb's
//  website. It combines the space and speed 
//  efficiencies of BST and digital search tries.
//
// Testcases: 
//   basic operations:
//     insert, remove, search and traverse
/////////////////////////////////////////////////////
#include "TernaryTree.h"
#include <string>
#include <string.h>

int main() {

	TernaryTree tree;
	
	//********************************************************
	// insert
	//********************************************************
	cout << "1) Insert: 5 words to tree: apple, as, at, may "
		<< "& to\n";
	tree.insert("apple");
	tree.insert("as");
	tree.insert("at");
	tree.insert("may");
	tree.insert("to");
	cout << endl;
	
	cout << "2) Traverse: words inserted are:\n";
	tree.traverse();
	cout << endl << endl;

	//********************************************************
	// search
	//********************************************************
	cout << "3) Search:\n";
	cout << "Search for 'to': " << endl;
	tree.searchString("to");
	cout << endl;

	cout << "Search for 'ast': " << endl;
	tree.searchString("ast");
	cout << endl;

	cout << "Search for 'as': " << endl;
	tree.searchString("as");
	cout << endl;

	cout << "Search for 'orange': " << endl;
	tree.searchString("orange");
	cout << endl;

	cout << "Search for 'apple': " << endl;
	tree.searchString("apple");
	cout << endl << endl;

	//********************************************************
	// remove
	//********************************************************
	cout << "4) Remove: delete at and apple\n";
	cout << "Delete 'at'...";
	tree.remove("at");
	cout << endl;

	cout << "Delete 'apple'...";
	tree.remove("apple");
	cout << endl << endl;

	cout << "5) Traverse: words left are:\n";
	tree.traverse();
	cout << endl << endl;

	system("pause");
	return 0;
}