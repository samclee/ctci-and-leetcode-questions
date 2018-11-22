#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void printVec(vector<int> v) {
	cout << '[';
	for (auto e : v)
		cout << e << ' ';
	cout << "]\n";
}

void merge(vector<int>& a, vector<int> b, int aSz, int bSz) {
	int aPtr = aSz - 1;
	int bPtr = bSz - 1;
	int masterPtr = aSz + bSz - 1;

	while (bPtr >= 0) {

		if (aPtr >= 0 && a[aPtr] > b[bPtr]) {
			a[masterPtr] = a[aPtr];
			aPtr--;
		}
		else {
			a[masterPtr] = b[bPtr];
			bPtr--;
		}

		masterPtr--;
	}
}

int main() {
	vector<int> a = {1, 3, 5, 8, 0, 0, 0, 0};
	vector<int> b = {2, 4, 6, 7};

	printVec(a);
	printVec(b);

	merge(a, b, 4, 4);
	printVec(a);

	return 0;
}