#include <iostream>
#include <vector>
#include <map>
#include <string>
using std::cout;
using std::vector;
using std::map;
using std::string;

vector<string> groupAnagrams(const vector<string>& words) {
	vector<string> solution;
	map<string, vector<string>> wordMap;

	for (auto word : words) {
		string sortedWord = word;
		sort(sortedWord.begin(), sortedWord.end()); // get its base word
		
		wordMap[sortedWord].push_back(word);
	}

	for (auto v : wordMap) {
		vector<string> curVec = v.second;
		for (auto s : curVec)
			solution.push_back(s);
	}

	return solution;
}

int main() {

	vector<string> words{"foo", "bar", "rab", "ofo", "oof", "arb", "baz"};

	vector<string> solutionAry = groupAnagrams(words);
	for (auto w : solutionAry)
		cout << "\"" << w << "\" ";

	cout << '\n';

	return 0;
}