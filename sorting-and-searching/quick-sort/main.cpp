#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void printVec(const vector<int>& ary) {
	for (auto i : ary)
		cout << i << " ";
	cout << '\n';
}

void mySwap(vector<int>& ary, int a, int b) {
	int temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}

int partition(vector<int>& ary, int l, int r) {
	int pivot = ary[(l + r) / 2];

	while ( l <= r) {
		// find elt on left side of pivot to move to right
		while (ary[l] < pivot) l++;

		// find elt on right side of pivot to move to left
		while (ary[r] > pivot) r--;

		if (l <= r) {
			mySwap(ary, l, r);
			l++;
			r--;
		}
	}

	return l;
}

void quicksort(vector<int>& ary, int l, int r) {
	int index = partition(ary, l, r); // this index is guaranteed to be in the right spot

	if (l < index - 1){
		quicksort(ary, l, index-1);

	}
	if (index < r) {
		quicksort(ary, index, r);
	}
}

int main() {
	vector<int> testVec{3, 2, 5, 1, 4, 6, 0};

	cout << "Original array\n";
	printVec(testVec);

	quicksort(testVec, 0, testVec.size() - 1);

	cout << "Sorted array\n";
	printVec(testVec);
}