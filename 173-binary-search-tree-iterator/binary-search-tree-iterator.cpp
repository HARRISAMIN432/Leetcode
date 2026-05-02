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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
        p = -1;
    }
    
    int next() {
        p++;
        return a[p];
    }
    
    bool hasNext() {
        return (p + 1 < a.size()) ? true : false;
    }

private:
    vector<int> a;
    int p;

    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        a.push_back(root->val);
        inOrder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */