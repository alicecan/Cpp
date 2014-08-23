#include <iostream>
using namespace std;

// header file contains the function declarations
// and member variables. This is an implementation
// of a binary tree template
template <class T>
class BTree {
private:
	// member variables
	class TreeNode {
		friend class BTree; // allow BTree to use private members of TreeNode
		T value;
		TreeNode *left;
		TreeNode *right;
		TreeNode (T val, TreeNode *left=NULL, TreeNode *right=NULL) {
			this->value = val;
			this->left = left;
			this->right = right;
		}
	};
	TreeNode *root;
	
	// helper member functions
	void delTree(TreeNode *tnode);
	void insert(TreeNode *&tnode, T val);
	void remove(TreeNode *&tnode, T val);
	void otherRemove(TreeNode *&tnode);
	int compare(TreeNode *t1, TreeNode *t2) const;
	void displayInOrder(TreeNode *tnode) const;
	void displayPreOrder(TreeNode *tnode) const;
	void displayPostOrder(TreeNode *tnode) const;

public:
	// constructor & destructor
	BTree() { root = NULL; }
	~BTree() { delTree(root); }

	// insert and remove
	void insert(T val) { insert(root, val); }
	void remove(T val) { remove(root, val); }
	
	// traverse the tree
	void printInOrder() { displayInOrder(root); }
	void printPreOrder() { displayPreOrder(root); }
	void printPostOrder() { displayPostOrder(root); }
};