#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void printVec(const vector<int>& ary) {
	for (auto i : ary)
		cout << i << " ";
	cout << '\n';
}

void merge(vector<int> &v, int l, int r) {
	int m = (l + r) / 2;
}

void mergesort(vector<int> &v, int l, int r) {
	int m = (l + r) / 2;
	mergesort(v, l, m);
	mergesort(v, m + 1, r);
	merge(v, l, r);
}

int main() {
	vector<int> testVec{3, 2, 5, 1, 4, 6, 0};

	cout << "Original array\n";
	printVec(testVec);

	mergesort(testVec, 0, testVec.size() - 1);

	cout << "Sorted array\n";
	printVec(testVec);
}