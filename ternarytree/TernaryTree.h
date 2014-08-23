#include <iostream>
using namespace std;

// header file contains
// the function declarations
// and member variables
class TernaryTree {
private:
	// member variables
	struct TreeNode {
		char value;
		bool strEnd;
		TreeNode *left;
		TreeNode *right;
		TreeNode *equal;
		TreeNode (char val, TreeNode *left=NULL, TreeNode *equal=NULL, TreeNode *right=NULL) {
			this->value = val;
			this->strEnd = false;
			this->left = left;
			this->equal = equal;
			this->right = right;
		}
	};
	TreeNode *root;

	// helper member functions
	void delTree(TreeNode *tnode);
	int findLen(char *str) const;
	void insert(TreeNode *&tnode, char *str, int len);
	void remove(TreeNode *&tnode, char *str, int len);
	void search(TreeNode *tnode, char *str, int len) const;
	void traverse(TreeNode *tnode, string str) const;
	
public:
	// constructor & destructor
	TernaryTree() { root = NULL; }
	~TernaryTree() { delTree(root); }

	// insert and remove
	void insert(char *s) { insert(root, s, findLen(s)); }
	void remove(char *s) { remove(root, s, findLen(s)); }
	
	// traverse the tree
	void searchString(char *s) { search(root, s, findLen(s)); }
	void traverse() { traverse(root, ""); }
};
