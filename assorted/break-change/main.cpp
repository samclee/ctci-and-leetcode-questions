#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::string;

vector<int> currVals{1, 5, 10, 25, 100, 500, 1000, 2000, 5000, 10000};
vector<string> names{"pennie(s)", "nickel(s)", "dime(s)", "quarter(s)",
						"$1 bill(s)", "$5 bill(s)", "$10 bill(s)",
						"$20 bill(s)", "$50 bill(s)", "$100 bill(s)"};

int relevantVal(float amt) {	
	int i = 0;
	for (i = currVals.size()-1; i >= 0; i--) {
		if (currVals[i] <= amt)
			break;
	}
	return i;
}

vector<int> makeChange(int amt, vector<int> change) {
	if (amt == 0)
		return change;

	int id = relevantVal(amt);
	change[id] = amt / currVals[id];

	float nextAmt = amt % currVals[id];

	return makeChange(nextAmt, change);
} // recurse

vector<int> makeChange(float amt) {
	vector<int> change(currVals.size(), 0);

	int newAmt = (int) (amt * 100);

	return makeChange(newAmt, change);
} // driver

int main() {
	vector<int> change = makeChange(487.42);
	for (int i = 0; i < change.size(); i++) {
		cout << change[i] << " " << names[i] << '\n';
	}

}
