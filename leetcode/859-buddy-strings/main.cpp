#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
using std::cout;
using std::vector;
using std::string;
using std::set;
using std::pair;
using std::make_pair;

bool buddyString(string A, string B) {
	if (A.size() != B.size())
        return false;
    
    vector<pair<char, char>> diffs;
    set<char> seen;
    bool dupFound = false;
    
    for (int i = 0; i < A.size(); i++) {
        if (seen.find(A[i]) == seen.end())
            seen.insert(A[i]);
        else
            dupFound = true;
        
        if (A[i] != B[i]) {
            diffs.push_back(make_pair(A[i], B[i]));
        }
    }
    
    if (diffs.size() == 2)
        return (diffs[0].first == diffs[1].second) && (diffs[0].second == diffs[1].first);
    else if (diffs.size() == 0)
        return dupFound;
    
    return false;
}

int main(int argv, char* argc[]) {
	string A(argc[1]);
	string B(argc[2]);

	cout << "\"" << A << "\" and \"" << B << "\" are ";
	if (!buddyString(A, B))
		cout << "not ";
	cout << "buddy strings.\n";

	return 0;
}