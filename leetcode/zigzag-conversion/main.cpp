#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;

void addChars(vector<char>& v, char c, int n) {
	if (n < 1)
		return;

	for (int i = 0; i < n; i++) {
		v.push_back(c);
	}
}

vector< vector<char> > zigzag(string s, int numRows) {
	vector<vector<char>> sol(numRows);

	int i = 0;

	while (i < s.size()) {
		for (int traveled = 0; traveled < numRows && i < s.size(); traveled++, i++) {
			sol[traveled].push_back(s[i]);
		} // going down

		for (int traveled = numRows-1; traveled > -1 && i < s.size(); traveled--) {
			if (traveled == 0 || traveled == numRows-1)
				addChars(sol[traveled], ' ', numRows-2);
			else {
				addChars(sol[traveled], ' ', numRows-2-traveled);
				sol[traveled].push_back(s[i]);
				addChars(sol[traveled], ' ', traveled-1);
				i++;
			}
		} // going up
	}
	return sol;
}

string convert(string s, int numRows){
	vector<string> sol(numRows);

	if (numRows <= 0)
		return "";
	if (numRows == 1)
		return s;

	int i = 0;
	while (i < s.size()) {
		for (int traveled = 0; traveled < numRows && i < s.size(); traveled++, i++) {
			sol[traveled] += s[i];
		} // going down

		for (int traveled = numRows-2; traveled > 0 && i < s.size(); traveled--, i++) {
			sol[traveled] += s[i];
		} // going up
	}

	// make matrix into string
	string totalStr = "";
	for (auto row : sol) {
		totalStr += row;
	}

	return totalStr;
}

int main() {
	string test = "PAYPALISHIRING";

	auto zigzagStr = zigzag(test, 4);
	auto str = convert(test, 3);

	for (auto r : zigzagStr) {
		for (auto c : r) {
			cout << c;
		}
		cout << '\n';
	}

	cout << str << '\n';


	return 0;
}