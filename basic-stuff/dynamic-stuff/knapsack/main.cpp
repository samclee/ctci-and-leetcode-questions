#include <iostream>
#include <vector>
using namespace::std;

int subset_sum_helper(int cur, vector<int> wgts, vector<vector<int>>& tbl, int target) {
	// if wgt of curelt > target, definitely can't use it, return tbl[curelt-1][target]
	if (wgts[cur] > target) {
		return tbl[cur-1][target];
	}
	// else, return max of not using it and using it
	return max(tbl[cur-1][target], wgts[cur] + tbl[cur-1][target-wgts[cur]]);
}

// bottom-up
int subset_sum(vector<int> wgts, int target) {
	// make wgts.size+1 x target+1 mx
	wgts.insert(wgts.begin(),0);
	vector<vector<int>> tbl(wgts.size(), vector<int>(target+1,0));
	// run helper on each
	for (int i=1; i < wgts.size(); i++) {
		for (int t=0; t <= target; t++) {
			tbl[i][t] = subset_sum_helper(i,wgts,tbl,t);
		}
	}

	return tbl[tbl.size()-1][target];
}

// top-down
int lcs(string s1, string s2, int i1, int i2, vector<vector<int>>& memo) {
	if (i1==-1 || i2==-1)
		return 0;
	else if (memo[i1][i2] != -1)
		return memo[i1][i2];
	else if (s1[i1] == s2[i2]) {
		memo[i1][i2] = 1+lcs(s1,s2,i1-1,i2-1,memo);
	}
	else if (s1[i1] != s2[i2]) {
		memo[i1][i2] = max(lcs(s1,s2,i1,i2-1,memo),lcs(s1,s2,i1-1,i2,memo));
	}

	return memo[i1][i2];
}

int lcs(string s1, string s2) {
	vector<vector<int>> memo(s1.size(),vector<int>(s2.size(),-1));

	return lcs(s1,s2,s1.size()-1,s2.size()-1,memo);
}


int main() {
	//vector<int> test{1,4,7,2,5,3};
	vector<int> test{2,2,3};
	cout << lcs("adbc","acbdcp") << endl;
	return 0;
}