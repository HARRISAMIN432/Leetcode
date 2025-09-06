/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            vector<int> tmp(s);
            for(int i = 0; i < s; i++) {
                Node* node = q.front();
                q.pop();
                tmp[i] = node->val;
                for(Node* nde : node->children) q.push(nde); 
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};