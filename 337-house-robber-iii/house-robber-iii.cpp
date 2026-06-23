class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        int take = root->val, skip = 0;
        if(root->left) take += rob(root->left->left) + rob(root->left->right);
        if(root->right) take += rob(root->right->left) + rob(root->right->right);
        skip = rob(root->left) + rob(root->right);
        return dp[root] = max(take, skip);
    }
};