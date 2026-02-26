class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        long long total = 0;
        dfs(root, total, (long long)targetSum);
        total += pathSum(root->left, targetSum);
        total += pathSum(root->right, targetSum);
        return total;
    }

private:
    void dfs(TreeNode* root, long long &total, long long target) {
        if (!root) return;
        if ((long long)root->val == target)
            total++;
        dfs(root->left, total, target - root->val);
        dfs(root->right, total, target - root->val);
    }
};