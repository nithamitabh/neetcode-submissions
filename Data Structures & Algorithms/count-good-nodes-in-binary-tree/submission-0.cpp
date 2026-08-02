/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int cnt = 0;
    void dfs(TreeNode *root,int mxSoFar){
        if(!root) return;
        if(root->val >= mxSoFar) cnt++;
        mxSoFar = max(mxSoFar,root->val);
        dfs(root->left,mxSoFar);
        dfs(root->right,mxSoFar);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return cnt;
    }
};
