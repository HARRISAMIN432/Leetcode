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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        bool reversee = false;
        vector<int> temp;
        int curr = 1;
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level > curr) {
                if(reversee) reverse(temp.begin(), temp.end());
                reversee = !reversee;
                ans.push_back(temp);
                temp.clear();
                curr++;
            }
            temp.push_back(node->val);
            if(node->left) q.push({node->left, level + 1});
            if(node->right) q.push({node->right, level + 1});
        }
        if(reversee) reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        return ans;
    }
};