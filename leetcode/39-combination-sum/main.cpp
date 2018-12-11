#include <iostream>
#include <vector>
using std::cout;
using std::vector;


void buildSum(const vector<int>& candidates, vector<int> inProg, int curPos, int target, vector<vector<int>>& sols) {
	// base case
	if (target == 0) {
		sols.push_back(inProg);
		return;
	}

	// try using nums from curPos on
	for (int i = curPos; i < candidates.size(); i++) {
		int curNum = candidates[i];

		if (target < curNum) {
			return;
		}
		else {
			inProg.push_back(curNum); // try using cur num
			buildSum(candidates, inProg, i, target - curNum, sols);
			inProg.pop_back(); // okay take it back
		}

	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> sols;
	
	vector<int> sorted(candidates);
	sort(candidates.begin(), candidates.end());
	
	vector<int> inProg{};

	buildSum(candidates, inProg, 0, target, sols);

	return sols;
}

int main() {
	vector<int> test{2,3,6,7};
	vector<vector<int>> sums = combinationSum(test,7);
	for (vector<int> comb : sums) {
		for (int e : comb) {
			cout << e << " ";
		}
		cout << '\n';
	}
	return 0;
}