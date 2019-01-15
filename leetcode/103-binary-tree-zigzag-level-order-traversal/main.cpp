/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* rt, int level, vector<vector<int>>& sol) {
    if (!rt) return;
    
    if (level==sol.size()) {
        sol.push_back(vector<int>{rt->val});
    }
    else if (level % 2 == 0) { 
        sol[level].push_back(rt->val);
    }
    else {
       sol[level].insert(sol[level].begin(),rt->val); 
    }
    
    helper(rt->left,level+1,sol);
    helper(rt->right,level+1,sol);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> sol;
    helper(root, 0, sol);
    return sol;
}

int main(){
    return 0;
}