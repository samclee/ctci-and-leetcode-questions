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
		int l = curInd + 1, r = nums.size() - 1;

		while (l < r) {
			int lrSum = nums[l] + nums[r];

			if (lrSum == -curNum) {
				sols.push_back({curNum, nums[l], nums[r]});
				
				r--;
				while (nums[r] == nums[r+1])
					r--;

				l++;
				while (nums[l] == nums[l-1])
					l++;
			}
			else if (lrSum > -curNum) {
				r--;
				while (nums[r] == nums[r+1])
					r--;
			} // too large, reduce positive part
			else if (lrSum < - curNum) {
				l++;
				while (nums[l] == nums[l-1])
					l++;
			} // too small, reduce negative part (or add positive part)
		} // move ptrs inward, check lrSums

		curInd++;
		while (nums[curInd] == nums[curInd-1])
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