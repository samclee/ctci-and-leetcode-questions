#include <iostream>
#include <stack>
#include <array>
using std::cout;
using std::stack;
using std::array;

void moveN(int numDisks, int srcStk, int destStk, int bufStk, array<stack<int>, 3>& stacks) {

	if (numDisks <= 0)
		return;

	// move top n-1 disks to buffer
	moveN(numDisks-1, srcStk, bufStk, destStk, stacks);

	// move btm disk to dest
	int curEl = stacks[srcStk].top();
	stacks[srcStk].pop();
	stacks[destStk].push(curEl);

	// move n-1 disks on buffer to dest
	moveN(numDisks-1, bufStk, destStk, srcStk, stacks);

}

int main(int argv, char *argc[]) {
	array<stack<int>, 3> stacks;

	int disks = atoi(argc[1]);
	cout << "Stack 0\n|Bottom| ";
	for (int i = 0; i < disks; i++) {
		stacks[0].push(disks - i);
		cout << disks - i << " ";
	}
	cout << "|Top|\n";

	moveN(disks, 0, 2, 1, stacks);

	int stack2size = stacks[2].size();
	cout << "Stack 2\n|Top| ";
	for (int i = 0; i < stack2size; i++) {
		cout << stacks[2].top() << " ";
		stacks[2].pop();
	}
	cout << "|Bottom|\n";

	return 0;
}