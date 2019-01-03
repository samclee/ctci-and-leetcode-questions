#ifndef GRUFF_H
#define GRUFF_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <utility>
using std::cout;
using std::cin;
using std::ifstream;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::make_pair;

/* ========== Node class ========== */
class Node {
private:
	set<string> neighbors;
	bool marked;
public:
	Node();

	bool isMarked() const;
	set<string> getNeighbors() const;
	void printNeighbors() const;
	
	void mark();
	void addNeighbor(string);
	void removeNeighbor(string);
};

Node::Node() : marked(false) {}

bool Node::isMarked() const {
	return marked;
} // isMarked()

set<string> Node::getNeighbors() const {
	return neighbors;
} // getNeighbors()

void Node::printNeighbors() const {
	for (set<string>::iterator n = neighbors.begin(); n != neighbors.end(); n++)
			cout << "(" << *n << ") ";
	cout << '\n';
} // printNeighbors()

void Node::mark() {
	marked = true;
} // mark()

void Node::addNeighbor(string s) {
	neighbors.insert(s);
} // addNeighbor()

void Node::removeNeighbor(string s) {
	neighbors.erase(s);
} // removeNeighbor()

/* ========== Graph class ========== */
class Graph {
protected:
	map<string, Node> nodes;
	string eatSpaces(string) const;
	pair<string,string> parse(string) const;
public:
	Graph();
	Graph(string);

	set<string> getNeighborsOf(string);
	set<string> getNeighborsTo(string);
	void mark(string);
	bool isMarked(string);
	map<string, Node> getNodes() const;

	void addNode(string);
	void removeNode(string);
	virtual void addEdge(string, string);
	virtual void removeEdge(string, string);
	
	void interactiveAdd();	
	unsigned int size() const;
	void print();
};

Graph::Graph() {}

Graph::Graph(string filename) {
	ifstream ifs(filename);

	string line;
	while (getline(ifs, line)) {
		pair<string,string> endpoints = parse(line);
		if (endpoints.second == "") {
			addNode(endpoints.first);
		}
		else {
			addEdge(endpoints.first, endpoints.second);
		}
	}
} // file constructor

set<string> Graph::getNeighborsOf(string name) {
	if (nodes.find(name) != nodes.end())
		return nodes[name].getNeighbors();
	return set<string>();
} // getNode()

set<string> Graph::getNeighborsTo(string name) {
	set<string> to;
	for (auto iter: nodes) {
		set<string> curNbors = iter.second.getNeighbors();
		if (curNbors.find(name) != curNbors.end())
			to.insert(iter.first);
	}
	
	return to;
} // getNode()

void Graph::mark(string name) {
	if (nodes.find(name) != nodes.end())
		nodes[name].mark();
} // mark()

bool Graph::isMarked(string name){
	if (nodes.find(name) != nodes.end())
		return nodes[name].isMarked();
	return false;
}

map<string, Node> Graph::getNodes() const {
	return nodes;
}

void Graph::addNode(string s) {
	nodes[s];
} // addNode()

void Graph::removeNode(string s) {
	nodes.erase(s);
	for (map<string, Node>::iterator src = nodes.begin(); src != nodes.end(); src++) {
		src->second.removeNeighbor(s);
	}
} // removeNode()

void Graph::addEdge(string src, string dst) {
	nodes[src].addNeighbor(dst);
	addNode(dst);
} // addEdge()

void Graph::removeEdge(string src, string dst) {
	if (nodes.find(src) == nodes.end())
		return;
	nodes[src].removeNeighbor(dst);
} // removeEdge()

pair<string,string> Graph::parse(string line) const {
	string src, dst;

	int midpoint = line.find("->");
	if (midpoint == string::npos) {
		src = line;
	}
	else {
		src = line.substr(0, midpoint);
		src = eatSpaces(src);
		dst = line.substr(midpoint+2);
		dst = eatSpaces(dst);
	}
	
	return make_pair(src, dst);
} // parse file input into node names

void Graph::interactiveAdd() {
	cout << "Enter edges with the format: src -> dst.\nEnter done to finish.\n";
	
	string line;
	while (getline(cin, line) && line != "done") {
		pair<string,string> endpoints = parse(line);
		if (endpoints.second == "") {
			addNode(endpoints.first);
		}
		else {
			addEdge(endpoints.first, endpoints.second);
		}
	}
} // interactively add nodes

unsigned int Graph::size() const {
	return nodes.size();
} // size()

string Graph::eatSpaces(string s) const {
	int l = 0, r = s.size()-1;
	while (l <= r && s[l] == ' ') l++;
	while (r >= l && s[r] == ' ') r--;

	if (r < l)
		return "";

	return s.substr(l, r-l+1);
} // eatSpaces()

void Graph::print(){
	for (map<string, Node>::iterator src = nodes.begin(); src != nodes.end(); src++) {
		cout << '[';
		if (src->second.isMarked()) cout << 'x';
		else cout << ' ';

		cout << "] (" << src->first << ") has edges to: ";
		src->second.printNeighbors();
	}
} // prints()

/* ========== Undirected Graph class ========== */
class UndirectedGraph : public Graph {
public:
	UndirectedGraph();
	UndirectedGraph(string);

	virtual void addEdge(string, string);
	virtual void removeEdge(string, string);
};

UndirectedGraph::UndirectedGraph() {}

UndirectedGraph::UndirectedGraph(string filename) : Graph() {
	ifstream ifs(filename);

	string line;
	while (getline(ifs, line)) {
		pair<string,string> endpoints = parse(line);
		if (endpoints.second == "") {
			addNode(endpoints.first);
		}
		else {
			addEdge(endpoints.first, endpoints.second);
		}
	}
} // file constructor

void UndirectedGraph::addEdge(string src, string dst) {
	nodes[src].addNeighbor(dst);
	nodes[dst].addNeighbor(src);
} // addEdge()

void UndirectedGraph::removeEdge(string src, string dst) {
	if (nodes.find(src) == nodes.end() || nodes.find(dst) == nodes.end())
		return;
	nodes[src].removeNeighbor(dst);
	nodes[dst].removeNeighbor(src);
} // removeEdge()

#endif