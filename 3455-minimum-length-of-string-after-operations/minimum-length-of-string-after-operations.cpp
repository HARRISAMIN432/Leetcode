class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int ans = 0;
        for (int f : freq) {
            if (f == 0) continue;
            if (f % 2 == 1) ans += 1;
            else ans += 2;
        }
        return ans;
    }
};