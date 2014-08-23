#include "TernaryTree.h"
#include <string>

// all these functions use the same methodology: starting
// from the root node and start comparing the currnt character
// with the parent's whether it's lower (go to left), the 
// same (go to equal) or higher (go to right).

//********************************************************
// insert adds a word to the tree
//********************************************************
void TernaryTree::insert(TreeNode *& tnode, char *str, int len) {
		static int cnt = 0;

		if (tnode == NULL) {
			tnode = new TreeNode(*str);
		}

		if (*str < tnode->value)
			insert(tnode->left, str, len);
		else if (*str > tnode->value)
			insert(tnode->right, str, len);
		else {
			if (*str != '\0') {
				cnt++;
				if (cnt == len) {
					tnode->strEnd = true;
					cnt = 0;
					return;
				}
				insert(tnode->equal, ++str, len);
			}
		}	
}

//********************************************************
// remove deletes a word from the tree
//********************************************************
void TernaryTree::remove(TreeNode *&tnode, char *str, int len) {
	static int tempCnt = 0;

	if (tnode == NULL) return;
	if (*str < tnode->value)
		remove(tnode->left, str, len);
	else if (*str > tnode->value)
		remove(tnode->right, str, len);
	else {
		if (*str != '\0') {
			tempCnt++;
			if (tempCnt == len) {
				tnode->strEnd = false;
				tempCnt = 0;
			}
			remove(tnode->equal, ++str, len);
		}
	}
}

//********************************************************
// findLen finds the length of the string
//********************************************************
int TernaryTree::findLen(char *str) const {
	int len = 0;
	while (*str) {
		len++;
		str++;
	}
	return len;
}

//********************************************************
// search finds the word based on the input string
//********************************************************
void TernaryTree::search(TreeNode *tnode, char *str, int len) const {
	static int count = 0;
	static int comparison = 0;
	bool found = false;
	
	if (tnode != NULL) {
		comparison++;
		if (*str < tnode->value)
			search(tnode->left, str, len);
		else if (*str > tnode->value)
			search(tnode->right, str, len);
		else {
			if (*str != '\0') {
				//cout << tnode->value <<  endl;
				count++;
				if ((count == len) && (tnode->strEnd == true)) {
					found = true;
					cout << "After " << comparison << " comparisons, word is found!" << endl;
					count=0; comparison=0;
					return;
				}
				search(tnode->equal, ++str, len);
			}
		}
	} else {	
		if (!found) { 
			cout << "After " << comparison << " comparisons, word is NOT found." << endl;
			//<< "\ncomparisons, it reaches the terminal of the tree and word is not found." << endl;
			count=0; comparison=0;
		}
	}
}

//********************************************************
// traverses lists all the words in the tree
//********************************************************
void TernaryTree::traverse(TreeNode *tnode, string str) const {
	if (tnode == NULL) return;
	
	string s(1, tnode->value);
	traverse(tnode->left, str);
	
	str.append(s);
	if (tnode->strEnd == true) {	
		cout << str << " ";
	} 

	traverse(tnode->equal, str);

	traverse(tnode->right, str.substr(0, str.size()-1));
}

//********************************************************
// deletes all the nodes
//********************************************************
void TernaryTree::delTree(TreeNode *tnode) {
	if (tnode == NULL) return;
	delTree(tnode->left);
	delTree(tnode->equal);
	delTree(tnode->right);
	
	delete tnode;
	
}