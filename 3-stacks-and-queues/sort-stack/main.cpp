#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> sortStack(stack<int> stk) {
	stack<int> sortedStk;
	stack<int> buffer;

	// empty every elt of original stack into the sorted stack
	while (!stk.empty()) {
		int toBeInserted = stk.top();
		stk.pop();

		// insert elt into sorted stack by removing all elt smaller
		while (!sortedStk.empty() && sortedStk.top() < toBeInserted) {
			buffer.push(sortedStk.top());
			sortedStk.pop();
		}

		// insert elt into sorted stack
		sortedStk.push(toBeInserted);
		
		// move elts from buffer back on
		while (!buffer.empty()) {
			sortedStk.push(buffer.top());
			buffer.pop();
		}
	}

	return sortedStk;
}

stack<int> sortStack2(stack<int> stk) {
	stack<int> sortedStk;

	// empty every elt of original stack into the sorted stack
	while (!stk.empty()) {
		int toBeInserted = stk.top();
		stk.pop();

		// insert elt into sorted stack by removing all elt smaller
		while (!sortedStk.empty() && sortedStk.top() < toBeInserted) {
			stk.push(sortedStk.top());
			sortedStk.pop();
		}

		// insert elt into sorted stack
		sortedStk.push(toBeInserted);
	}

	return sortedStk;
}

int main() {
	vector<int> testAry{2, 5, 4, 6, 9, 3, 7};
	stack<int> testStk;
	stack<int> resultStk;

	// original stack 
	cout << "----Original----\n|Bottom| ";
	for (int i = 0; i < testAry.size(); i++) {
		cout << testAry[i] << " ";
		testStk.push(testAry[i]);
	}
	cout << " |Top|\n";

	resultStk = sortStack2(testStk);

	cout << "----Sorted----\n|Top| ";
	while (!resultStk.empty()) {
		cout << resultStk.top() << " ";
		resultStk.pop();
	}
	cout << " |Bottom|\n";

	return 0;
}