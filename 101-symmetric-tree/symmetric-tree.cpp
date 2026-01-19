class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return isInverted(root->left, root->right);
    }

private:
    bool isInverted(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left || !right || left->val != right->val) return false;
        return isInverted(left->left, right->right) && isInverted(left->right, right->left);
    }
};