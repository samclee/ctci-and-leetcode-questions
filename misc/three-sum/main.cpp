#include <iostream>
#include <vector>
using std::cout;
using std::vector;

vector< vector<int> > threeSum(vector<int> nums) {
	vector<vector<int> > sols;

	sort(nums.begin(), nums.end());
	
	// for each negative number
	// put pointers at left and right side
	  // if sum of left and right is too positive, move right ptr <- (skipping repeats)
	  // if too negative, move left ptr -> (skipping repeats)
	  // if they meet, move number
	  // if it equals zero, push answer and continue

	return sols;
}

int main() {
	vector<int> testVec{-1, 0, 1, 2, -1, -4, -1};

	vector<vector<int>> sols = threeSum(testVec);
	for (auto sol : sols) {
		cout << "[";
		for (auto i : sol) {
			cout << i << ", ";
		}
		cout << "]\n";
	}

}