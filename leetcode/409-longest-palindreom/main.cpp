#include <map>
#include <string>
#include <cout>
using std::map;
using std::string;
using std::cout;

int longestPalindrome(string s) {
    map<char, int> freqOf;
    
    for (char c : s)
        freqOf[c]++;
    
    int foundOdd = 0, sol = 0;
    for (auto iter : freqOf) {
        if (iter.second % 2 != 0) {
            sol--;
            foundOdd = 1;
        }
        sol += iter.second;
        
    }
    
    return sol + foundOdd;
}

int main() {
	string test("aaaaaaabbbbbbcccccdddd");

	cout << "Longest palindrome constructed from " 
			<< test << " is " << longestPalindrome(test) << '\n';

	return 0;
}