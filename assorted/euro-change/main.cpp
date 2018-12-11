#include <iostream>
#include <vector>
using std::vector;
using std::cout;

vector<float> euroVals{0.01, 0.02, 0.05, 0.1, 0.5, 1,
						5, 10, 50, 100, 500};

vector<float> euroValsAlt{1, 2, 5, 10, 50, 100,
						500, 1000, 5000, 10000, 50000};

int relevantVal(float amt) {	
	int i = 0;
	for (int i = euroVals.size()-1; i >= 0; i--) {
		if (euroVals[i] <= amt)
			break;
	}

	return i;
}

vector<int> breakEuro(int amt, vector<int> change) {
	if (amt == 0)
		return change;

	int id = relevantVal(amt);
	change[id] = amt % euroValsAlt[id];

	float nextAmt = amt / euroValsAlt[id];

	return breakEuro(nextAmt, change);
}

vector<int> driver(float amt) {
	vector<int> change;

	int newAmt = (int) (amt * 100);
	return breakEuro(newAmt, change);
}

int main() {
	vector<int> change = breakEuro(100.0);
}