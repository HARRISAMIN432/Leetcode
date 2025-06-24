class Solution {
public:
    void helper(int ob, int cb, int n, string& temp, vector<string>& ans) {
        if (ob > n || cb > ob)
            return;
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        helper(ob + 1, cb, n, temp, ans);
        temp.pop_back();
        temp.push_back(')');
        helper(ob, cb + 1, n, temp, ans);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        if (n == 1)
            return {"()"};
        vector<string> ans;
        string temp = "";
        helper(0, 0, n, temp, ans);
        return ans;
    }
};