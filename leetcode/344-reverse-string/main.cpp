#include <string>
using std::string;

string reverseString(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        char t = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i] = t;
    }
    
    return s;
}