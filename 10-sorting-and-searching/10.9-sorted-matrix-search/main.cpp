#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool sortedMatrixSearch(vector<vector<int>> mx, int target) {
	int row = 0, col = mx[0].size()-1;

	while (row < mx.size() && col >= 0) {
		if (mx[row][col] == target) {
			return true;
		}
		else if (mx[row][col] > target)
			col--;
		else if (mx[row][col] < target)
			row++;
	}
	return false;
}

int main() {
	vector<vector<int>> m{{1,3,5,7,9},
						  {2,4,6,8,11},
						  {3,5,8,13,14},
						  {10,11,12,15,20}};
	int target = 10;
	cout << target << " is in the matrix: " << sortedMatrixSearch(m, target) << '\n';
}