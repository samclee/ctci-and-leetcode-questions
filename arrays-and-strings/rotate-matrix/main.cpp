#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printMx(vector< vector<char> > mx) {
	for (auto row : mx) {
		for (auto el : row) {
			cout << el << " ";
		}
		cout << '\n';
	}
}

void rotateMx(vector< vector<char> >& mx) {
	int dim = mx.size();
	vector< vector<char> > newMx(dim, vector<char>(dim, '!'));

	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			newMx[col][dim - 1 - row] = mx[row][col];
		}
	}

	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			mx[row][col] = newMx[row][col];
		}
	}
} // n^2 space, n^2 time

void rotateMxNoExtra(vector< vector<char> >& mx) {

	for (int layer = 0; layer < mx.size() / 2; layer++) {
		int start = layer;
		int end = mx.size() - 1 - layer;

		for (int i = start; i < end; i++) {
			int distIn = i - start;

			// store TL
			char temp = mx[start][i];

			// BL TO TL
			mx[start][i] = mx[end - distIn][start];

			// BR TO BL
			mx[end - distIn][start] = mx[end][end - distIn];

			// TR TO BR
			mx[end][end - distIn] = mx[i][end];

			// TL TO TR
			mx[i][end] = temp;

		}
	}
} // 1 space, n^2 time

int main() {
	int dim = 5;
	char el = 65;
	vector<vector<char>> testMx;

	for (int i = 0; i < dim; i++) {
		testMx.push_back( vector<char>() );
		for (int j = 0; j < dim; j++) {
			testMx[i].push_back(el + dim * i + j);
		}
	}
	cout << "----Before----" << '\n';
	printMx(testMx);

	rotateMxNoExtra(testMx);

	cout << "----After----" << '\n';
	printMx(testMx);
}