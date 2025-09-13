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
    int sumOfNode(int &count, TreeNode*& root) {
        if(!root) return 0;
        count++;
        return root->val + sumOfNode(count ,root->left) + sumOfNode(count ,root->right);
    }

    void dfs(TreeNode* root, int &ans) {
        if(!root) return;
        int count = 0;
        int sum = sumOfNode(count, root);
        if(sum / count == root->val) ans++;
        if(root->left) dfs(root->left, ans);
        if(root->right) dfs(root->right, ans);
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};