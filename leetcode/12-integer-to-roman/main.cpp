#include <vector>
#include <string>
using namespace std;

vector<string> oneUnits{"I", "X", "C", "M"};
vector<string> fiveUnits{"V", "L", "D"};

string toRoman(int digit, int place) {
    string rom = "";
    if (digit == 4)
        rom = oneUnits[place] + fiveUnits[place];
    else if (digit == 9)
        rom = oneUnits[place] + oneUnits[place+1];
    else {
        if (digit >= 5)
            rom = fiveUnits[place];
        
        int numOnes = digit % 5;
        for (int i = 0; i < numOnes; i++)
            rom += oneUnits[place];
    }
    
    return rom;
}

string intToRoman(int num) {
    string sol = "";
    
    int place = 0;
    while (num > 0) {
        sol = toRoman(num % 10, place) + sol;
        
        place++;
        num /= 10;
    }
    
    return sol;
}

int main() {

}