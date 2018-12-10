#include <climits>
#include <iostream>
using std::cout;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, long min, long max) {
    if (!root)
        return true;
    if (root->val <= min || root->val >= max)
        return false;
    
    return helper(root->left, min, root->val) && helper(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

int main() {
	// bleh I don't want to make a test case
	return 0;
}