class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        vector<vector<int>> dp(words.size(), vector<int>(words.size(), -1));
        return f(0, -1, words, dp);
    }

private:
    int f(int i, int p, vector<string>& words, vector<vector<int>>& dp) {
        if (i == words.size())
            return 0;
        if (dp[i][p + 1] != -1)
            return dp[i][p + 1];
        int skip = f(i + 1, p, words, dp), take = 0;
        if ((p == -1) || (words[i].size() == words[p].size() + 1 && compare(words[p], words[i])))
            take = 1 + f(i + 1, i, words, dp);
        return dp[i][p + 1] = max(skip, take);
    }

    bool compare(string& shorter, string& longer) {
        if (longer.size() != shorter.size() + 1)
            return false;
        int i = 0, j = 0;
        bool skipped = false;
        while (i < shorter.size() && j < longer.size()) {
            if (shorter[i] == longer[j]) {
                i++, j++;
            } else {
                if (skipped)
                    return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }
};