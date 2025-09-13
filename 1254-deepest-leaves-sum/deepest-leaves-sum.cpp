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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        while(!q.empty()) {
            temp.clear();
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        int ans = 0;
        for(int i = 0; i < temp.size(); i++) ans += temp[i];
        return ans;
    }
};