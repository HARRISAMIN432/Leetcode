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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> sizes;
        int tmp = 1, s;
        while(!q.empty()) {
            sizes.push_back(tmp);
            tmp = 0, s = q.size();
            bool miss = false;
            for(int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(!node->left) miss = true;
                if(node->left) {
                    tmp++;
                    if(miss) return false;
                    q.push(node->left);
                }
                if(!node->right) miss = true;
                if(node->right) {
                    tmp++;
                    if(miss) return false;
                    q.push(node->right);
                }
            }
        } 
        for(int i = 1; i < sizes.size() - 1; i++) if(sizes[i] / 2 != sizes[i - 1]) return false;
        return true;
    }
};