#include <set>
#include <string>
#include <iostream>
using std::set;
using std::string;
using std::cout;

bool isVowel(char x) {
    set<char> vowels{'a', 'e', 'i', 'o', 'u',
					'A', 'E', 'I', 'O', 'U'};
    return (vowels.find(x) != vowels.end());
}

string reverseVowels(string s) {
    int l = 0, r = s.size()-1;
    
    while (l < r) {
    	while (l < r && !isVowel(s[l])) l++;
    	while (l < r && !isVowel(s[r])) r--;
    	if (l >= r)
    		break;

        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        
        l++;
        r--;
    }
    
    return s;
}

int main() {
	string s("hello");
	cout << reverseVowels(s) << '\n';

	return 0;
}