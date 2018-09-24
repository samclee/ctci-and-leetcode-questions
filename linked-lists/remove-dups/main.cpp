/*
 *	CTCI 2.1
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
	int val;
	Node *next;
	Node(int v) : val(v), next(NULL) {} 
};

void rmDup(Node *head) {
	set<int> seen;
	Node *prev = NULL;
	Node *cur = head;
	
	while (cur) {
		if (seen.find(cur->val) == seen.end()) {
			seen.insert(cur->val);
			prev = cur;
		} // cur is first of its kind
		else {
			prev->next = cur->next;
		} // cur is a duplicate

		cur = cur->next;
	}
} // n^2 time, n space

void rmVal(Node *head, int val) {
	Node *prev = head;
	Node *cur = prev->next;

	while (cur) {
		if (cur->val != val) {
			prev = cur;
		} // cur doesn't have val we want to remove, move prev
		else {
			prev->next = cur->next;
		} // cur has the forbidden value, don't move prev, but point its next one forward

		cur = cur->next;
	}
}

void rmDupNoExtra(Node *head) {
	Node *cur = head;

	while (cur) {
		rmVal(cur, cur->val);
		cur = cur->next;
	}
} // same functionality as rmDup, but no extra data structure is used. n^2 time

void printList(Node *head) {
	Node *cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	// create test data
	vector<int> v{6, 3, 7, 3, 4, 4, 1, 3, 6};
	Node *head = new Node(v[0]);
	Node *cur = head;
	for (int i = 0; i < v.size() - 1; i++) {
		cur->next = new Node(v[i + 1]);
		cur = cur->next;
	}

	// print original test data
	cout << "Original:\t";
	printList(head);

	// remove duplicates;
	rmDupNoExtra(head);

	// print test data
	cout << "After:\t\t";
	printList(head);

	cur = head;

	return 0;
}