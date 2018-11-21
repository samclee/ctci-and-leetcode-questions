#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int binarySearchIter(vector<int> v, int target) {
	int l = 0, r = v.size()-1, m = 0;

	while (l <= r) {
		m = (l + r) / 2;

		int val = v[m];

		if (val == target)
			return m;
		else if (val < target)
			l = m + 1;
		else if (val > target)
			r = m - 1;
	}

	return -1;
}

int binarySearchRecur(int l, int r, vector<int> v, int target) {
	if (l > r)
		return -1;

	int m = (l + r) / 2;
	int val = v[m];
	if (val == target)
		return m;
	else if (val < target)
		return binarySearchRecur(m + 1, r, v, target);
	else if (val > target)
		return binarySearchRecur(l, m - 1, v, target);

	return -1;
}

int main() {
	vector<int> testVec{1,3,23,48,55,75,89,90,112};

	cout << binarySearchIter(testVec, 55) << '\n';
	cout << binarySearchRecur(0, testVec.size()-1,testVec, 89) << '\n';
	return 0;
}