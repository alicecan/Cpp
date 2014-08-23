#include "BTree.h"

//********************************************************
// insert adds an element to the tree
//********************************************************
template <class T>
void BTree<T>::insert(TreeNode *& tnode, T val) {
	if (tnode == NULL)
		tnode = new TreeNode(val);

	if (tnode->value == val)
		return;
	else if (val < tnode->value)
		insert(tnode->left, val);
	else 
		insert(tnode->right, val);
}


//********************************************************
// remove deletes a word from the tree
//********************************************************
template <class T>
void BTree<T>::remove(TreeNode *&tnode, T val) {
	if (tnode == NULL) return;
	if (val < tnode->value)
		remove(tnode->left, val);
	else if (val > tnode->value)
		remove(tnode->right, val);
	else
		otherRemove(tnode);
}

template <class T>
void BTree<T>::otherRemove(TreeNode *&tnode) {
	TreeNode *temp = tnode;  // save the original node pointer
	TreeNode *newRight;

	if (tnode->right == NULL)
		tnode = tnode->left;
	else if (tnode->left == NULL)
		tnode = tnode->right;
	else {
		// find the minimum value in the left node 
		// of the right subtree and insert the original
		// left-tree child
		newRight = tnode->right;
		while (newRight->left != NULL) 
			newRight = newRight->left;
		newRight->left = tnode->left;

		// update the tnode to be the right child
		tnode = tnode->right;

		// delete the original node
		delete temp;
	}
}

//********************************************************
// trasverse the tree: in-order, pre-order and post-order
//********************************************************
template <class T>
void BTree<T>::displayInOrder(TreeNode *tnode) const {
	if (tnode != NULL) {
		displayInOrder(tnode->left);
		cout << tnode->value << " ";
		displayInOrder(tnode->right);
	}
}

template <class T>
void BTree<T>::displayPreOrder(TreeNode *tnode) const {
	if (tnode != NULL) {
		cout << tnode->value << " ";
		displayPreOrder(tnode->left);
		displayPreOrder(tnode->right);
	}
}

template <class T>
void BTree<T>::displayPostOrder(TreeNode *tnode) const {
	if (tnode != NULL) {
		displayPostOrder(tnode->left);
		displayPostOrder(tnode->right);
		cout << tnode->value << " ";
	}
}

//********************************************************
// used with the other class types to compare two objects
//********************************************************
template <class T>
int BTree<T>::compare(TreeNode *t1, TreeNode *t2) const {
	if (t1->value > t2->value)
		return 1;
	else if (t1->value < t2->value)
		return -1;
	else
		return 0;
}

//********************************************************
// deletes all the nodes
//********************************************************
template <class T>
void BTree<T>::delTree(TreeNode *tnode) {
	if (tnode == NULL) return;
	delTree(tnode->left);
	delTree(tnode->right);
	delete tnode;
}