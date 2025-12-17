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
    void countNodes(TreeNode* root, TreeNode* parent, int &ans) {
        if(!root) return;
        if(!parent || root->val >= parent->val) ans++;
        if(!parent) parent = root;
        else if(parent->val < root->val) parent = root;
        countNodes(root->left, parent, ans);
        countNodes(root->right, parent, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        countNodes(root, NULL, ans);
        return ans;
    }
};