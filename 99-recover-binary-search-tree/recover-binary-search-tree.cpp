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
    void inOrder(TreeNode* root, vector<int>& order)  {
        if(!root) return;
        inOrder(root->left, order);
        order.push_back(root->val);
        inOrder(root->right, order);
    }

    void write(TreeNode* &root, vector<int>& order, int& i) {
        if(!root) return;
        write(root->left, order, i);
        root->val = order[i];
        i++;
        write(root->right,order, i);
    }

    void recoverTree(TreeNode* root) {
        vector<int> order;
        inOrder(root, order);
        int lidx = -1, ridx = -1;
        sort(order.begin(), order.end());
        int i = 0;
        write(root, order, i);
    }
};