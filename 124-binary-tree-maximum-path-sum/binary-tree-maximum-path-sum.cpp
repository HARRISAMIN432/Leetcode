class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; 
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int &maxSum) {
        if (!node) return 0;
        int left = max(dfs(node->left, maxSum), 0);
        int right = max(dfs(node->right, maxSum), 0);
        int currPath = node->val + left + right;
        maxSum = max(maxSum, currPath);
        return node->val + max(left, right);
    }
};