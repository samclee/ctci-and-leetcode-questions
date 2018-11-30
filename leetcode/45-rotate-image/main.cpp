#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void printMx(vector<vector<int>> mx) {
	for (auto r : mx) {
		for (auto e : r)
			cout << e << ' ';
		cout << '\n';
	}
}

void rotate(vector<vector<int>>& matrix) {
    int lastIndex = matrix[0].size()-1;
    int numLayers = matrix[0].size() / 2;
    
    for (int layer = 0; layer < numLayers; layer++) {
    	int reverseLayer = lastIndex - layer;
        for (int offset = layer; offset <= lastIndex - layer - 1; offset++) {
        	int reverseOffset = lastIndex - offset;

        	int temp = matrix[layer][offset];
        	matrix[layer][offset] = matrix[reverseOffset][layer];
        	matrix[reverseOffset][layer] = matrix[reverseLayer][reverseOffset];
        	matrix[reverseLayer][reverseOffset] = matrix[offset][reverseLayer];
        	matrix[offset][reverseLayer] = temp;
        }
    }
}

int main() {
	vector<vector<int>> testMx{{1,2,3,7},{5,6,1,8},{9,8,7,5},{4,3,2,0}};
	printMx(testMx);

	rotate(testMx);
	cout << '\n';
	printMx(testMx);
	return 0;
}