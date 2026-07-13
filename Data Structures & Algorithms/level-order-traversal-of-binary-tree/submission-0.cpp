class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int lvlSize = q.size();
            vector<int> lvl;

            for (int i = 0; i < lvlSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                lvl.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            res.push_back(lvl);
        }

        return res;
    }
};