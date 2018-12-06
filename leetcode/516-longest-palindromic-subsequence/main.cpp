#include <iostream>
#include <string>
using std::cout;
using std::string;

int findSubseq(string s, int l, int r) {
    int len = r - l + 1;
    if (len == 0 || len == 1) {
        return len;
    }
    else if (s[l] == s[r]) {
        return 2 + findSubseq(s, l+1,r-1);
    }
    else {
        return max(findSubseq(s,l+1,r), findSubseq(s,l,r-1));
    }
    return -1;
}

// okay this techically works
int longestPalindromeSubseq(string s) {
    return findSubseq(s, 0, s.size()-1);
}

int longestPalindromeSubseqDP(string s) {

}

int main() {
	string test("abcdeca");
	cout << "Longest thingy of " << test
			<< " is " << longestPalindromeSubseq(test) << '\n';
	return 0;
}