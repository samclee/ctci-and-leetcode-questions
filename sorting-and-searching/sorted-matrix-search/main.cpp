#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool sortedMatrixSearch(vector<vector<int>> mx, int target) {
	int row = mx.size()-1, col = mx[0].size()-1;

	while (row >= 0 && col >= 0) {
		if (mx[row][col] == target) {
			cout << row << " " << col << '\n';
			return true;
		}
		else if (mx[row][col] > target)
			row--;
		else
			col--;
	}
	return false;
}

int main() {
	vector<vector<int>> m{{1,3,5,7,9},
							{2,4,6,8,10},
							{3,7,8,13,14},
							{10,11,12,15,20}};
	int target = 7;
	cout << target << " is in the matrix: " << sortedMatrixSearch(m, target) << '\n';
}