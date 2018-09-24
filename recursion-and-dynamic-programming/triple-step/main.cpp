#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int findWays(int steps, vector<int>& memo) {
	// if steps is invalid/already known, return val
	if (steps < 0)
		return 0;
	else if (memo[steps] != -1)
		return memo[steps];

	// memo[steps] is unknown, calculate and return
	memo[steps] = 0;
	for (int i = 1; i < 4; i++) 
		memo[steps] += findWays(steps - i, memo);

	return memo[steps];
}

int main(int argv, char *argc[]) {
	int n = atoi(argc[1]);
	vector<int> memo(n+1, -1);
	memo[0] = 1;
	
	cout << "For " << c << " step(s) there are " << findWays(c, memo) << " ways to complete it.\n";

	return 0;
}