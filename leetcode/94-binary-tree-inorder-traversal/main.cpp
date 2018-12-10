#include <vector>
using std::vector;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void addInorder(TreeNode* root, vector<int>& sol) {
    if (!root)
        return;
    
    addInorder(root->left, sol);
    sol.push_back(root->val);
    addInorder(root->right, sol);
} 

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> sol;
    if (!root)
        return sol;
    
    addInorder(root->left, sol);
    sol.push_back(root->val);
    addInorder(root->right, sol);
    
    return sol;
}

int main() {
	// yeah...tree stuff is easier to run on leetcode cuz they have a visualizer

	return 0;
}