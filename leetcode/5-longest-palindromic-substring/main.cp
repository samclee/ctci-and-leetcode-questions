#include <string>
#include <iostream>
using std::cout;
using std::string;

string longestPalindrome(string s) {
	int len = s.size();
	int maxLen = 1;
	int start = 0;

	for (int i = 1; i < len; i++) {
		// odd palindrome
		for (int l=i-1, r=i; l >= 0 && r < len; l--,r++) {
			if (s[l] != s[r])
				break;
			int newLen = r - l + 1;
			if (newLen > maxLen) {
				maxLen = newLen;
				start = l;
			}
		}

		// even palindrome
		for (int l=i-1, r=i+1; l >= 0 && r < len; l--,r++) {
			if (s[l] != s[r])
				break;
			int newLen = r - l + 1;
			if (newLen > maxLen) {
				maxLen = newLen;
				start = l;
			}
		}
	} // for every char in s

	return s.substr(start, maxLen);
}

int main() {
	cout << longestPalindrome("forgeeksskeegfor") << '\n';

	return 0;
}