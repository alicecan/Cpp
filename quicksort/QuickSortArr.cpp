///////////////////////////////////////////////////// 
// Author: hard worker (github/alicecan) 
// 
// Description: 
//	This program implements a template version of
//  quicksort using array.
// 
// Testcases:  
//		1. array w/ known numbers (small set, done)
//		2. array w/ random numbers (will do) 
///////////////////////////////////////////////////// 

#include <iostream>
//#include <cstlib>
using namespace std;

template <class T>
class QuickSortArr {
private:
	T val;
public:
	void quickSort(T val[], int low, int high);
	void swap(T &a, T &b);
	void display(T val[], int size) const; 
};

int main() {
	QuickSortArr<int> qs;
	int a[] = {50,7,2,100,2,8,6};
	//int a[] = {3, 2, 2, 8, 2, 7};
	int size = 7;
	cout << "Before sorting: \n";
	qs.display(a, size);
	cout << endl;

	qs.quickSort(a, 0, size-1);
	cout << "After quick sort: \n";
	qs.display(a, size);
	cout << endl;

	system("pause");
	return 0;
}

//******************************************************** 
// quicksort 
//******************************************************** 
template <class T>
void QuickSortArr<T>::quickSort(T val[], int low, int high) {
	// set the first element to be used in comparisons
	T firstIndex = val[low]; 
	int left = 0;
	int right = 0;

	// step 1: from low to high, find the first element that is
	// bigger than the firstIndex element
	// save the index
	for (int i=low+1; i<=high; i++) {
		if (firstIndex < val[i]) {
			left = i;
			break;
		}
		left = low;
	}
	
	// step 2: from high downto low, find the first element that
	// is smaller than the firstIndex element,
	// save the index
	for (int j=high; j>low; j--) {
		if (firstIndex > val[j]) {
			right = j;
			break;
		}
		right = high;
	}
	
	// step 3: if left index is smaller than the right index
	// swap the corresponding elments
	// else if left index is bigger than the right index
	// swap the right element with the firstIndex element
	// else done
	if (left < right) 
		swap(val[left], val[right]);
	else if (left > right)
		swap(val[firstIndex], val[right]);
	else
		return;

	// do it recursively
	quickSort(val, low, right-1);	
	quickSort(val, right+1, high);
}

//******************************************************** 
// display the array contents
//******************************************************** 
template <class T>
void QuickSortArr<T>::display(T val[], int size) const {
	for (int i=0; i<size; i++) {
		cout << val[i] << " ";
	}
	cout << endl;
}

//******************************************************** 
// swap two numbers
//******************************************************** 
template <class T>
void QuickSortArr<T>::swap(T &a, T &b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
}