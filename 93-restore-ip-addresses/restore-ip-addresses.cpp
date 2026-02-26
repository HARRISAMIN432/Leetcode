class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cur;
        dfs(0, 0, s, cur, ans);
        return ans;
    }

private:
    void dfs(int idx, int parts, string &s, string &cur, vector<string> &ans) {
        if (parts == 4) {
            if (idx == s.size()) ans.push_back(cur.substr(0, cur.size() - 1)); 
            return;
        }
        int rem = s.size() - idx;
        if (rem < (4 - parts) || rem > 3 * (4 - parts)) return;
        int num = 0;
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            if (len > 1 && s[idx] == '0') break;
            num = num * 10 + (s[idx + len - 1] - '0');
            if (num > 255) break;
            int prevLen = cur.size();
            cur += to_string(num) + ".";
            dfs(idx + len, parts + 1, s, cur, ans);
            cur.resize(prevLen);
        }
    }
};