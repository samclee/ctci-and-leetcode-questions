#include <iostream>
#include <queue>
#include <vector>
using std::queue;
using std::vector;
using std::cout;

bool BFS(const vector< vector<int> >& graph, int a, int b) {
	vector<bool> visited(graph.size(), false);
	visited[a] = true;

	queue<int> toVisit;
	toVisit.push(a);

	while (!toVisit.empty()) {
		int cur = toVisit.front();
		toVisit.pop();

		if (cur == b)
			return true;

		for (auto nbor : graph.at(cur)) {
			if (!visited[nbor]) {
				visited[nbor] = true;
				toVisit.push(nbor);
			}
		} // push all unvisited neighbors
	}

	return false;
}

bool routeExists(const vector< vector<int> >& graph, int a, int b) {
	return BFS(graph, a, b) || BFS(graph, b, a);
}

void printGraph(vector< vector<int> > graph) {
	for (int i = 0; i < graph.size(); i++) {
		cout << i << ": ";
		for (auto nbor : graph.at(i)) {
			cout << nbor << ' ';
		}
		cout << '\n';
	}
}

int main(int argv, char *argc[]) {
	int a = atoi(argc[1]);
	int b = atoi(argc[2]);

	vector< vector<int> > graph;
	graph.push_back(vector<int>{1, 4, 5}); // vertex 0
	graph.push_back(vector<int>{3, 4});
	graph.push_back(vector<int>{1});
	graph.push_back(vector<int>{2, 4});
	graph.push_back(vector<int>{});
	graph.push_back(vector<int>{});

	cout << "===== Graph =====\n";
	printGraph(graph);

	cout << "Route between " << a << " and " << b << " [[does";
	if (!routeExists(graph, a, b))
		cout << " not";
	cout << "]] exist\n";
	
	return 0;
}