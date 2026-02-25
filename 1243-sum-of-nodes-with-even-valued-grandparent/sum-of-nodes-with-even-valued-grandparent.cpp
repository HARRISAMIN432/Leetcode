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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        queue<tuple<TreeNode*, int, int>> q;
        if(root->left) q.push(make_tuple(root->left, root->val, -1));
        if(root->right) q.push(make_tuple(root->right, root->val, -1));
        int sum = 0;
        while(!q.empty()) {
            TreeNode* node = get<0>(q.front());
            int parent = get<1>(q.front());
            int grandparent = get<2>(q.front());
            q.pop();
            if(grandparent % 2 == 0) sum += node->val;
            if(node->left) q.push(make_tuple(node->left, node->val, parent));
            if(node->right) q.push(make_tuple(node->right, node->val, parent));
        }        
        return sum;
    }
};