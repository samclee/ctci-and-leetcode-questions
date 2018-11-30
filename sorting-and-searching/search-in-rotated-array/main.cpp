#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int rotatedSearch(vector<int> v, int tg) {
	int l = 0, r = v.size()-1, m = 0;

	while (l <= r) {
		m = (l + r) / 2;
		int vl = v[l], vr = v[r], vm = v[m];
		
		if (vm == tg) 
			return m;

		if (v[l] < v[r]) {
			// binary search
			if (vm < tg)
				l = m + 1;
			else if (vm > tg)
				r = m - 1;
		}
		else {
			// rotated binary search
			bool cond1 = vl < vm && vl <= tg && tg < vm;
			bool cond2 = vl > vm && (vl <= tg || tg < vm);

			if (cond1 || cond2)
				r = m - 1;
			else
				l = m + 1;
		}
	}

	return -1;
}

int main() {
	vector<int> testVec{15,16,19,20,25,1,3,4,5,7,10,14};
	vector<int> targets{15,19,5,14};

	for (auto t : targets) {
		cout << t << " found at index: " << rotatedSearch(testVec, t) << '\n';
	}

	return 0;
}