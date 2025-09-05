/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<pair<Node*, int>> q;
        int curr = 1;
        q.push({root, 1});
        vector<Node*> temp;
        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level > curr) {
                curr = level;
                for (int i = 0; i < temp.size() - 1; i++)
                    temp[i]->next = temp[i + 1];
                temp[temp.size() - 1]->next = NULL;
                temp.clear();
            }
            temp.push_back(node);
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        for (int i = 0; i < temp.size() - 1; i++)
            temp[i]->next = temp[i + 1];
        temp[temp.size() - 1]->next = NULL;
        return root;
    }
};