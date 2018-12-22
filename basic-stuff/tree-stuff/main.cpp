#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using std::cout;
using std::string;
using std::vector;
using std::queue;
using std::stack;

/* ========== TreeNode ========== */
class TreeNode { 
public:
	string val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(string s) : val(s), left(NULL), right(NULL) {}
};

TreeNode* arrayToTree(vector<string> nodes, TreeNode* parent, int childIndex) {
	if (childIndex >= nodes.size() || nodes[childIndex] == "")
		return NULL;

	TreeNode* root = new TreeNode(nodes[childIndex]);
	root->left = arrayToTree(nodes, root, (2 * childIndex) + 1);
	root->right = arrayToTree(nodes, root, (2 * childIndex) + 2);

	return root;
}

TreeNode* arrayToTree(vector<string> nodes) {
	if (nodes.size() == 0)
		return NULL;

	TreeNode* root = new TreeNode(nodes[0]);
	root->left = arrayToTree(nodes, root, 1);
	root->right = arrayToTree(nodes, root, 2);

	return root;
}

void BFS(TreeNode* root) {
	if (!root) return;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* cur = q.front();
		q.pop();
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
		cout << cur->val << " ";
	}
	cout << '\n';
}

void DFS_iter(TreeNode* root) {
	if (!root) return;

	stack<TreeNode*> stk;
	stk.push(root);

	while (!stk.empty()) {
		TreeNode* cur = stk.top();
		stk.pop();
		if (cur->left)
			stk.push(cur->left);
		if (cur->right)
			stk.push(cur->right);
		cout << cur->val << " ";
	}
	cout << '\n';
}

void DFS_recur(TreeNode* root) {
	if (!root) return;

	cout << root->val << " ";
	DFS_recur(root->left);
	DFS_recur(root->right);
}

void inorder(TreeNode* root) {
	if (!root) return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void preorder(TreeNode* root) {
	if (!root) return;

	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode* root) {
	if (!root) return;

	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

int main() {
	vector<string> ary{"a", "n", "f", "c", "", "p", "j", ""};
	TreeNode* r = arrayToTree(ary);
	preorder(r);
}