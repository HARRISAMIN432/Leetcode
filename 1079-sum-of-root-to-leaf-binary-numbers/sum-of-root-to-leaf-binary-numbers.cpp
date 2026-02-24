class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        string s;
        int sum = 0;
        dfs(root, s, sum);
        return sum;
    }

private:
    int binToDec(const string &s) {
        int ans = 0, power = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') ans += (1 << power);
            power++;
        }
        return ans;
    }

    void dfs(TreeNode* root, string &s, int &sum) {
        if (!root) return;
        s.push_back(root->val + '0');
        if (!root->left && !root->right) {
            sum += binToDec(s);
        } else {
            dfs(root->left, s, sum);
            dfs(root->right, s, sum);
        }
        s.pop_back();
    }
};