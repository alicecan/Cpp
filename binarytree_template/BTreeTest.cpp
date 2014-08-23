/////////////////////////////////////////////////////
// Description:
//	This program implements a template version of
//  binary serach tree (BST)
//
// Testcases: 
//   data types: int, string
//   basic operations: insert, remove and traverse
/////////////////////////////////////////////////////
#include "BTree.cpp"
#include <string>

int main() {
	
	BTree<int> tree; // integer tree
	BTree<string> stree; // string tree
	
	cout << "Inserting integers to tree: 6, 2, 10, 50, 12, 8\n";
	tree.insert(6);
	tree.insert(2);
	tree.insert(10);
	tree.insert(50);
	tree.insert(12);
	tree.insert(8);

	tree.printInOrder();
	cout << endl;

	cout << "\nDeleting 8...\n";
	cout << "Print in-order: " << endl;
	tree.remove(8);
	tree.printInOrder();
	cout << endl;

	cout << "\nDeleting 12...\n";
	tree.remove(12);
	cout << "Print in-order: " << endl;
	tree.printInOrder();
	cout << endl;

	cout << "Print pre-order: " << endl;
	tree.printPreOrder();
	cout << endl;

	cout << "Print post-order: " << endl;
	tree.printPostOrder();
	cout << endl << endl;

	cout << "Insert string to tree: apple, orange and mango " << endl;
	stree.insert("apple");
	stree.insert("orange");
	stree.insert("mango");
	cout << "Print in-order: " << endl;
	stree.printInOrder();
	cout << endl;

	cout << "\nDeleting orange...\n";
	stree.remove("orange");
	cout << "Print in-order: " << endl;
	stree.printInOrder();
	cout << endl << endl;

	system("pause");
	return 0;
}