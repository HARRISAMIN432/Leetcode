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
    bool isInverted(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left || !right || left->val != right->val) return false;
        return isInverted(left->left, right->right) && isInverted(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return isInverted(root->left, root->right);
    }
};