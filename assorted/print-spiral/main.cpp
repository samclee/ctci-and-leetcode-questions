#include <iostream>
#include <vector>
#include <iomanip>
using std::cout;
using std::vector;
using std::setw;

struct Vec {
	int x, y;
	Vec(int nx, int ny) : x(nx), y(ny) {}
	Vec operator+ (const Vec& other) {
		return Vec(this->x + other.x, this->y + other.y);
	}
	
	Vec operator- (const Vec& other) {
		return Vec(this->x - other.x, this->y - other.y);
	}
};

bool outOfBounds(vector<vector<int>> mx, Vec v) {
	return v.x < 0 || v.y < 0 || v.x >= mx.size() || v.y >= mx.size() || mx[v.y][v.x] != 0;
}

void printMx(vector<vector<int>> m) {
	for (auto r : m) {
		for (auto e : r) {
			cout << setw(3) << e << ' ';
		}
		cout << '\n';
	}
}

vector<vector<int>> spiral(int n) {
	vector<vector<int>> sol(n, vector<int>(n));

	vector<Vec> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int curDir = 0, curVal = 1, lastVal = n*n;
	Vec curPos(0, 0);

	while (curVal <= lastVal) {
		sol[curPos.y][curPos.x] = curVal;
		curPos = curPos + dirs[curDir];
		if (outOfBounds(sol, curPos)) {
			curPos = curPos - dirs[curDir];
			curDir = (curDir + 1) % 4;
			curPos = curPos + dirs[curDir];
		}
		curVal++;
	}
	
	return sol;
}

int main() {
	vector<vector<int>> mx = spiral(9);

	printMx(mx);

	return 0;
}