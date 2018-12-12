#include <iostream>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int sqrDig(int input) {
    int nI = 0;
    while (input > 0) {
        nI += pow(input % 10, 2);
        input /= 10;
    }
    
    return nI;
}

bool isHappy(int input, set<int> seen) {
    if (input == 1)
        return true;
    else if (seen.find(input) != seen.end())
        return false;
    else
        seen.insert(input);
    
    int newInput = sqrDig(input);
    return isHappy(newInput, seen);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int input = stoi(line);
        
        set<int> seen;
        cout << isHappy(input, seen) << endl;
    }
}
