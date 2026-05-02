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
    int diameter =0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left_subtree = dfs(root->left);
        int right_subtree = dfs(root->right);
        diameter= max(diameter,left_subtree+ right_subtree);
        return 1+max(left_subtree,right_subtree);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};
