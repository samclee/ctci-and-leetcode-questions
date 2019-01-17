#include <iostream>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
    if (word1.size()==0) return word2.size();
    else if (word2.size()==0) return word1.size();
    
    string nf1=word1.substr(1);
    string nf2=word2.substr(1);
    if (word1[0]==word2[0]) return minDistance(nf1,nf2);
    
    int a=minDistance(nf1,word2);
    int b=minDistance(word1,nf2);
    int c=minDistance(nf1,nf2);
    
    return 1+min(a,min(b,c));
}

int main() {

	cout << minDistance("horse", "osr") << endl;
	return 0;
}