#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::map;
using std::string;

int firstUniqChar(string s) {
    map<char, int> freqOf;
    
    for (auto c : s)
        freqOf[c]++;
    
    for (int i = 0; i < s.size(); i++) {
        if (freqOf[s[i]] == 1)
            return i;
    }
    
    return -1;
    
}

int main() {
	string test("beelzebub");
	cout << firstUniqChar(test) << '\n';

	return 0;
}