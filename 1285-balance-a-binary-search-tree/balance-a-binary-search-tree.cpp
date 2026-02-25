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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        dfs(root, nums);
        return buildTree(0, nums.size() - 1, nums);
    }

private:
    void dfs(TreeNode* root, vector<int> &nums) {
        if(!root) return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }

    TreeNode* buildTree(int l, int r, vector<int> &nums) {
        if(l > r) return NULL;
        int mid = (l + r) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(l, mid - 1, nums);
        node->right = buildTree(mid + 1, r, nums);
        return node;
    }
};