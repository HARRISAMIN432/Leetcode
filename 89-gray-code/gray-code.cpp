class Solution {
public:
    vector<int> grayCode(int n) {
        unordered_set<string> dp;
        vector<int> ans = {0};
        string s;
        for(int i = 0; i < n; i++) s += '0';
        dp.insert(s);
        f(n, s, ans, dp);
        return ans;
    }

private:
    void f(int n, string &s, vector<int> &ans, unordered_set<string> &dp) {
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '0') {
                s[i] = '1';
                if(dp.find(s) != dp.end()) {
                    s[i] = '0';
                    continue;
                }
                ans.push_back(binToDec(s));
                dp.insert(s);
                f(n, s, ans, dp);
            }
            else {
                s[i] = '0';
                if(dp.find(s) != dp.end()) {
                    s[i] = '1';
                    continue;
                }
                ans.push_back(binToDec(s));
                dp.insert(s);
                f(n, s, ans, dp);
            }
        }
    }

    int binToDec(string s) {
        int ans = 0, power = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '1') ans += pow(2, power);
            power++;
        }
        return ans;
    }
};