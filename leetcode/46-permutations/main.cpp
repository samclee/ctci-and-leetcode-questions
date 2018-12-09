#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;
using std::swap;

void printVec(vector<int> v) {
	cout << "{ ";
	for (auto e : v)
		cout << e << ' ';
	cout << "}\n";
}

void buildPerm(int start, vector<int> inProg, vector<vector<int>>& sols) {
	int len = inProg.size();

	if (start == len)
		sols.push_back(inProg);

	for (int i = start; i < len; i++) {
		swap(inProg[start], inProg[i]);
		buildPerm(start + 1, inProg, sols);
		swap(inProg[start], inProg[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> sols;
	vector<int> base(nums);

	buildPerm(0, base, sols);

	return sols;
}

int main() {
	vector<int>  base{1, 2, 3};
	vector<vector<int>> perms = permute(base);

	cout << "Permutations of ";
	printVec(base);

	for (auto perm : perms) {
		printVec(perm);
	}

	return 0;
}