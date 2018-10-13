#include <iostream>
#include <vector>
using std::cout;
using std::vector;

	// for each negative number
	// put pointers at left and right side
	  // if sum of left and right is too positive, move right ptr <- (skipping repeats)
	  // if too negative, move left ptr -> (skipping repeats)
	  // if they meet, move number
	  // if it equals zero, push answer and continue

vector< vector<int> > threeSum(vector<int> nums) {
	vector<vector<int> > sols;
	sort(nums.begin(), nums.end());

	int curInd = 0;

	while (curInd < nums.size() && nums[curInd] <= 0) {
		int curNum = nums[curInd];
		if (curInd > 0 && curNum == nums[curInd-1]) {
			curInd++;
			continue;
		}
		int l = curInd + 1, r = nums.size() - 1;

		while (l < r) {
			int lVal = nums[l], rVal = nums[r];
			int sum = curNum + lVal + rVal;

			if (sum == 0) {
				sols.push_back({curNum, lVal, rVal});
				
				while (l < r && lVal == nums[++l]);
				while (l < r && rVal == nums[--r]);
			}
			else if (sum > 0) {
				r--;
			} // too large, reduce positive part
			else if (sum < 0) {
				l++;
			} // too small, reduce negative part (or add positive part)
		} // move ptrs inward, check lrSums

		curInd++;
	} // iterate thru non-positive nums


	return sols;
} //threeSum()

int main() {
	vector<int> testVec{-1, 0, 1, 2, -1, -4, -1, 2, 3};

	vector<vector<int>> sols = threeSum(testVec);

	cout << "For vector:\n[";
	for (auto e : testVec)
		cout << e << ", ";
	cout << "]\nTriplets that sum to zero:\n";


	for (auto sol : sols) {
		cout << "[";
		for (auto i : sol) {
			cout << i << ", ";
		}
		cout << "]\n";
	}

}