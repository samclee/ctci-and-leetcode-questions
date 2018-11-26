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
	int leftPtr = l;
	int rightPtr = m + 1;
	vector<int> helper;

	while (leftPtr <= m && rightPtr <= r) {
		if (v[leftPtr] <= v[rightPtr]) {
			helper.push_back(v[leftPtr]);
			leftPtr++;
		}
		else {
			helper.push_back(v[rightPtr]);
			rightPtr++;
		}
	}

	while (leftPtr <= m) {
		helper.push_back(v[leftPtr]);
		leftPtr++;
	}

	while (rightPtr <= r) {
		helper.push_back(v[rightPtr]);
		rightPtr++;
	}

	for (int i = 0; i < helper.size(); i++) {
		v[l+i] = helper[i];
	}
}

void mergesort(vector<int> &v, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(v, l, m); // left
		mergesort(v, m + 1, r); // right
		merge(v, l, r);
	}
}

int main() {
	vector<int> testVec{3, 2, 5, 1, 4, 6, 0,7};

	cout << "Original array\n";
	printVec(testVec);

	mergesort(testVec, 0, testVec.size() - 1);

	cout << "Sorted array\n";
	printVec(testVec);
}