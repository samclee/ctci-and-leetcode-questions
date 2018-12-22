#include <iostream>
#include <stack>

using namespace std;

class StackQueue {
public:	
	stack<char> backStk;
	stack<char> frontStk;

	StackQueue() {}

	void push(char el) {
		backStk.push(el);
	} // push to the back of the queue

	void checkFront() {
		if (frontStk.empty()) {
			while (!backStk.empty()) {
				frontStk.push(backStk.top());
				backStk.pop();
			}
		} // if nothing is at the front, look for more elements
	}

	void pop() {
		checkFront();
		if (!frontStk.empty())
			frontStk.pop();
	} // pop from the front of the queue

	char top() {
		checkFront();
		if (!frontStk.empty())
			return frontStk.top();

		return '!';
	}

	bool isEmpty() {
		return backStk.empty() && frontStk.empty();
	}
};

int main() {
	StackQueue q;
	cout << q.isEmpty() << '\n';
	q.push('a');
	q.push('b');
	cout << q.top() << '\n';
	cout << q.isEmpty() << '\n';
	q.push('c');
	q.pop();
	q.pop();
	cout << q.top() << '\n';

	return 0;
}