#include "gruff.h"
#include <queue>
#include <stack>
#include <vector>
using std::queue;
using std::stack;
using std::vector;

bool contains_cycle(string cur, set<string> cur_path, Graph& g) {
	if (cur_path.find(cur) != cur_path.end())
		return true;

	if (g.isMarked(cur))
		return false;

	g.mark(cur);
	cur_path.insert(cur);
	
	set<string> neighbors = g.getNeighborsOf(cur);
	for (string n: neighbors) {
		if (contains_cycle(n, cur_path, g)) {
			return true;
		}
	}

	return false;
} // helper

bool contains_cycle(Graph g) {
	map<string, Node> all_nodes = g.getNodes();
	set<string> cur_path;
	for (auto iter : all_nodes) {
		if (contains_cycle(iter.first, cur_path, g)) {
			return true;
		}
	}

	return false;
} // driver

void top_sort(string cur, vector<string>& order, Graph& g) {
	// return if marked
	if (g.isMarked(cur))
		return;
	g.mark(cur);
	// for each nbor, visit
	set<string> neighbors = g.getNeighborsOf(cur);
	for (string n: neighbors) {
		top_sort(n, order, g);
	}
	//add to order
	order.insert(order.begin(), cur);
} // helper

void top_sort(Graph g) {
	// make list
	vector<string> order;
	// get all nodes
	map<string, Node> all_nodes = g.getNodes();
	// cycle through all and top sort them
	for (auto iter : all_nodes) {
		top_sort(iter.first, order, g);
	}

	cout << "Topologic sort\n";
	for (string e: order)
		cout << e;
	cout << '\n';
} // driver

bool top_sort_augmented(string cur, vector<string>& order, set<string> cur_path, Graph& g) {
	if (cur_path.find(cur) != cur_path.end())
		return false;
	if (g.isMarked(cur))
		return true;

	g.mark(cur);
	cur_path.insert(cur);

	set<string> neighbors = g.getNeighborsOf(cur);
	for (string n : neighbors) {
		if(!top_sort_augmented(n, order, cur_path, g))
			return false;
	}

	order.insert(order.begin(),cur);
	return true;
} // helper

bool top_sort_augmented(Graph g, vector<string>& order) {
	// create rec stack
	set<string> cur_path;

	// call helper on all
	cout << "Topologic sort\n";
	map<string, Node> all_nodes = g.getNodes();
	for (auto iter: all_nodes) {
		if (!top_sort_augmented(iter.first,order,cur_path, g)) {
			cout << "Graph is not a DAG\n";
			return false;
		}
	}
	for (string e: order)
		cout << e;
	cout << '\n';

	return true;
} // driver


void BFS(string start, Graph& g) {
	queue<string> q;
	g.mark(start);
	q.push(start);

	while (!q.empty()) {
		string next = q.front();
		q.pop();

		set<string> neighbors = g.getNeighborsOf(next);
		for (string n: neighbors) {
			if (!g.isMarked(n)) {
				g.mark(n);
				q.push(n);
			}
		}
	}
}

void DFS_recur(string start, Graph& g) {
	g.mark(start);

	set<string> neighbors = g.getNeighborsOf(start);
	for (string n: neighbors) {
		if (!g.isMarked(n))
			DFS_recur(n, g);
	}
}

void DFS_iter(string start, Graph& g) {
	stack<string> stk;
	g.mark(start);
	stk.push(start);

	while(!stk.empty()) {
		string next = stk.top();
		stk.pop();

		set<string> neighbors = g.getNeighborsOf(next);
		for (string n: neighbors) {
			if (!g.isMarked(n)) {
				g.mark(n);
				stk.push(n);
			}
		}
	}
}

int main() {
	Graph g("cyc.txt");
	g.print();
	vector<string> order;
	top_sort_augmented(g, order);


	return 0;
}