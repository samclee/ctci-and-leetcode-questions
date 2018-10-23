#include <vector>
#include <string>
#include <iostream>
#include <map>
using std::vector;
using std::string;
using std::cout;
using std::map;

map<char, string> digitsOf{
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"},
};

void buildCombo(string inProgress, string digits, vector<string>& sols) {
	if (digits.size() == 0) {
		if (inProgress.size() != 0)
			sols.push_back(inProgress);
		return;
	}

	char first = digits[0];
	string possible = digitsOf[first];

	for (auto c : possible) {
		buildCombo(inProgress + c, digits.substr(1), sols);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> sols;
	buildCombo("", digits, sols);

	return sols;
}

int main() {
	vector<string> sols = letterCombinations("23");
	for (auto s : sols)
		cout << "\"" << s << "\" ";
	cout << '\n';


	return 0;
}