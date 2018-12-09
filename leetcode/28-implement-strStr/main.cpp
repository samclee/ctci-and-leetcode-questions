#include <iostream>
#include<string>
using std::cout;
using std::string;

int strStr(string haystack, string needle) {
    int hLen = haystack.size();
    int nLen = needle.size();
    
    if (nLen == 0)
        return 0;
    else if (hLen < nLen)
        return -1;
    else if (hLen == nLen)
        return (haystack == needle) ? 0 : -1;
    else {
        int limit =  hLen - nLen;  
        for (int i = 0; i <= limit; i++) {
            if (haystack.substr(i, nLen) == needle)
                return i;
        }
    }
    
    return -1;
}

int main() {
	string h("asdasgfd"), n("gfd");
	cout << strStr(h, n) << '\n';
}