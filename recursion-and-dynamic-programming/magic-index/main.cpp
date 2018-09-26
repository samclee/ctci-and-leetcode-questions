#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int findMagicDistinct(vector<int> ary) {
	int L = 0, R = ary.size() - 1, M;

	while (L <= R) {
		M = (L + R) / 2;
		if (ary.at(M) > M)
			R = M - 1;
		else if (ary.at(M) < M) 
			L = M + 1;
		else if (ary.at(M) == M)
			return M;
	}

	return -1;
} // find magic index with the guarantee that all given values are distinct

void useTestAry(vector<int> testAry) {
int index = findMagicDistinct(testAry);
	cout << "Given array: [ ";
	for (auto i : testAry)
		cout << i << " ";
	cout << "]\nMagic index is [" << index << "]\n"; 
}

int main() {
	
	useTestAry(vector<int>{0, 1, 2, 5, 10, 300, 999});
	useTestAry(vector<int>{-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13});

	return 0;
}