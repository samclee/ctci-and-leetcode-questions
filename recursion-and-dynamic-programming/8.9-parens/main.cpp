#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;

void buildString(string inProgress, int numL, int numR, vector<string>& solutions) {

	if (numL == 0 && numR == 0) {
		solutions.push_back(inProgress);
	}
	else if (numL == 0 && numR != 0) {
		buildString(inProgress + ")", numL, numR-1, solutions);
	}
	else if (numL == numR) {
		buildString(inProgress + "(", numL-1, numR, solutions);
	}
	else if (numL < numR) {
		buildString(inProgress + "(", numL-1, numR, solutions);		
		buildString(inProgress + ")", numL, numR-1, solutions);
	}
}

int main(int argv, char* argc[]) {
	int n = atoi(argc[1]);

	vector<string> solutions;

	buildString("", n, n, solutions);

	for (auto s : solutions)
		cout << s << '\n';

	return 0;
}