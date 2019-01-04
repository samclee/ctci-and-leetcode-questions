#include <iostream>
#include <vector>
using namespace::std;

int subset_sum_helper(int cur, vector<int> wgts, vector<vector<int>>& memo, int target) {
	// if wgt of curelt > target, definitely can't use it, return memo[curelt-1][target]
	if (wgts[cur] > target) {
		return memo[cur-1][target];
	}
	// else, return max of not using it and using it
	return max(memo[cur-1][target], wgts[cur] + memo[cur-1][target-wgts[cur]]);
}

int subset_sum(vector<int> wgts, int target) {
	// make wgts.size+1 x target+1 mx
	vector<vector<int>> memo(wgts.size(), vector<int>(target+1,0));
	// run helper on each
	for (int i=1; i < wgts.size(); i++) {
		for (int t=0; t <= target; t++) {
			memo[i][t] = subset_sum_helper(i,wgts,memo,t);
		}
	}

	return memo[memo.size()-1][target];
}

int main() {
	//vector<int> test{1,4,7,2,5,3};
	vector<int> test{0,2,2,3};
	cout << subset_sum(test, 6) << endl;
	return 0;
}