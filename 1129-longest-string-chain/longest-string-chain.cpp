class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        vector<vector<int>> dp(words.size() + 1, vector<int>(words.size() + 2, 0));
        for(int i = words.size() - 1; i >= 0; i--) {
            for(int prev = i; prev >= -1; prev--) {
                int skip = dp[i + 1][prev + 1], take = 0;
                if ((prev == -1) || (words[i].size() == words[prev].size() + 1 && compare(words[prev], words[i])))
                    take = 1 + dp[i + 1][i + 1];
                dp[i][prev + 1] = max(skip, take);
            }
        }
        return dp[0][0];
    }

private:    
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