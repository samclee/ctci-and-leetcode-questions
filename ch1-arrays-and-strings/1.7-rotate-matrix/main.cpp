#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printMx(vector<vector<char>> mx) {
	for (auto row : mx) {
		for (auto el : row) {
			cout << el << " ";
		}
		cout << '\n';
	}
}

void rotateMx(vector<vector<int>> mx) {

}

void rotateMxNoExtra(vector<vector<char>> mx) {
	
}

int main() {
	int dim = 5;
	char el = 65;
	vector<vector<char>> testVec;

	for (int i = 0; i < dim; i++) {
		testVec.push_back( vector<char>() );
		for (int j = 0; j < dim; j++) {
			testVec[i].push_back(el + dim * i + j);
		}
	}

	printMx(testVec);
}