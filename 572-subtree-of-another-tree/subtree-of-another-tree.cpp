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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(f(root, subRoot)) return true;
        bool isSameLeft = isSubtree(root->left, subRoot);
        bool isSameRight = isSubtree(root->right, subRoot);
        return isSameLeft || isSameRight;
    }

private:
    bool f(TreeNode* p, TreeNode *q) {
        if(!p && !q) return true;
        if(!p || !q || p->val != q->val) return false;
        return f(p->left, q->left) && f(p->right, q->right);
    }
};