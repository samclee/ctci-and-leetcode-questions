#include <iostream>
#include <set>
#include <vector>
#include <string>

using std::cout;
using std::set;
using std::vector;
using std::string;

set<string> getPerms(string str) {
	set<string> perms;

	if (str.size() == 1) {
		perms.insert(str);
		return perms;
	}
	
	string first(1, str[0]);
	string noFirst = str.substr(1);
	set<string> noFirstPerms = getPerms(noFirst);
	
	string newPerm;
	for (auto p : noFirstPerms) {
		for (int i = 0; i <= p.size(); i++) {
			newPerm = p;
			newPerm.insert(i, first);
			perms.insert(newPerm);
		}
	}

	return perms;
}

int main() {
	string testStr = "abcd";
	set<string> solutions = getPerms(testStr);

	cout << "Permutations of string \"" << testStr << "\":\n";
	for (auto s : solutions)
		cout << s << " ";
	cout << '\n';

	return 0;
}