#include <iostream>
#include <vector>
using std::cout;
using std::vector;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

int DFS(TreeNode* root, int prVal, int pathLen) {
    if (!root || root->val != prVal)
        return pathLen;

    int lPath = DFS(root->left, root->val, pathLen+1);
    int rPath = DFS(root->right, root->val, pathLen+1);
    
    return max(lPath, rPath);
}

int longestUnivaluePath(TreeNode* root) {
	if (!root)
	    return 0;

	int maxLen = 0;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
	    TreeNode* curNode = q.front();
	    q.pop();
	    if (curNode->left)
	        q.push(curNode->left);
	    if (curNode->right)
	        q.push(curNode->right);
	    
	    int pathLen = DFS(curNode->left, curNode->val, 0) + DFS(curNode->right, curNode->val, 0);
	    maxLen = max(maxLen, pathLen);
	}

	return maxLen;
}

int main() {

	return 0;
}