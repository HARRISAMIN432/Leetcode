class Solution {
public:
    void helper(int num, int n, int k, vector<int>& temp, vector<vector<int>>& ans) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(num > n) return;
        temp.push_back(num);
        helper(num + 1, n, k, temp, ans);
        temp.pop_back();
        helper(num + 1, n, k, temp, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(1, n, k, temp, ans);
        return ans;
    }
};