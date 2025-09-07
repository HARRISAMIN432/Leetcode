class Solution {
public:
    int beautySum(string s) {
        vector<vector<int>> prefix(26, vector<int>(s.size() + 1, 0));
        int ans = 0;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < s.size(); j++)
                prefix[i][j + 1] = prefix[i][j] + ((s[j] == i + 'a') ? 1 : 0);
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int maxi = 0, mini = 501;
                for (int k = 0; k < 26; k++) {
                    maxi = max(maxi, prefix[k][j + 1] - prefix[k][i]);
                    if (prefix[k][j + 1] - prefix[k][i] > 0 &&
                        prefix[k][j + 1] - prefix[k][i] < mini) {
                        mini = prefix[k][j + 1] - prefix[k][i];
                    }
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};