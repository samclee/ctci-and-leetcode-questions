#include <iostream>
#include <vector>
#include <set>
using std::cout;
using std::vector;
using std::set;


void buildSum(const vector<int>& candidates, vector<int> inProg, int curPos, int target, set<vector<int>>& sols) {
	// base cases
	if (target == 0 && sols.find(inProg) == sols.end()) {
		sols.insert(inProg);
		return;
	}

	if (curPos >= candidates.size())
		return;

	// try using nums from curPos on
	for (int i = curPos; i < candidates.size(); i++) {
		int curNum = candidates[i];

		if (target < curNum) {
			return;
		}
		else {
			inProg.push_back(curNum); // try using cur num
			buildSum(candidates, inProg, i+1, target - curNum, sols);
			inProg.pop_back(); // okay take it back
		}

	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	set<vector<int>> sols;
	vector<int> sorted(candidates);
	sort(candidates.begin(), candidates.end());
	vector<int> inProg{};

	buildSum(candidates, inProg, 0, target, sols);
	vector<vector<int>> solVec(sols.begin(), sols.end());

	return solVec;
}

int main() {
	vector<int> test{10,1,2,7,6,1,5};
	vector<vector<int>> sums = combinationSum(test,8);
	for (vector<int> comb : sums) {
		for (int e : comb) {
			cout << e << " ";
		}
		cout << '\n';
	}
	return 0;
}