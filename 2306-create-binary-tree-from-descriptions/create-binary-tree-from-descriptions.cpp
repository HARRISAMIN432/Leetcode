class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        for(int i = 0; i < desc.size(); i++) {
            int val = desc[i][0], child = desc[i][1], isLeft = desc[i][2];
            if(!mp[val]) {
                TreeNode* node = new TreeNode(val);
                mp[val] = node;
            }
            if(!mp[child]) {
                TreeNode* ch = new TreeNode(child);
                mp[child] = ch; 
            }
            if(!isLeft) mp[val]->right = mp[child];
            else mp[val]->left = mp[child];
            par[child] = mp[val];
        }
        for (auto &it : mp) if (!par.count(it.first)) return it.second;
        return NULL;
    }

private:
    unordered_map<int, TreeNode*> mp;
    unordered_map<int, TreeNode*> par;
};