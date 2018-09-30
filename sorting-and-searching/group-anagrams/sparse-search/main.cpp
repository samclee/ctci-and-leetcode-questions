#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;

int sparseSearch(const vector<string>& v, string t) {
	int l = 0, r = v.size()-1, m = 0;

	while (l <= r) {
		m = (l + r) / 2;

		if (v[m] == "") {
			while (true) {
				if (scanL < l && scanR > r)
					return -999;
				else if (l <= scanL && v[scanL] != "") {
					m = scanL;
					break;
				}
				else if (scanR <= r && v[scanR] != "") {
					m = scanR;
					break;
				}
				scanL--;
				scanR++;
			}
		} // v[m] is empty, find real str

		if (v[m] == t)
			return m;
		else if (v[m] > t){
			r = m - 1;
		}
		else if (v[m] < t){
			l = m + 1;
		}
	}
	return -1;
}

int main() {
	string target = "ball";

	vector<string> testVec{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	int index = sparseSearch(testVec, target);

	cout << "Strings array" << '\n';
	for (string s : testVec)
		cout << '\"' << s << "\" ";
	cout << '\n';
	cout << '\"' << target << "\" found at index " << index << '\n';

	return 0;
}