#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;
using std::to_string;

string convert(string s) {
	int curNum = 0;
	char lastChar = ' ';
	string sol = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != lastChar && lastChar != ' ') {
			sol += (to_string(curNum) + lastChar);
			curNum = 0;
		}
		lastChar = s[i];
		curNum++;
	}
	sol += (to_string(curNum) + lastChar);

	return sol;
}

string countAndSay(int n) {
    string res("1");
    
    for (int i = 1; i < n; i++) {
        res = convert(res);
    }
    
    return res;
}

int main() {
	int n = 3;
	for (int i = 1; i <= 10; i++) {
		cout << i << ". " << countAndSay(i) << '\n';
	}

	return 0;
}