class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 1, right = -1, dec = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                right = i;
                break;
            }
            ans++;
        }
        if (right == -1)
            return s.size();
        for (int i = 0; i < right; i++)
            if (s[i] == '0')
                ans++;
        if (30 < s.size() - right - 1)
            return s.size() - right - 1;
        dec = pow(2, s.size() - right - 1);
        if (dec > k)
            return ans - 1;
        for (int i = right - 1; i >= 0; i--) {
            if ((30 < s.size() - i - 1 && s[i] == '1') || dec > k)
                return ans;
            if (s[i] == '1')
                dec += pow(2, s.size() - i - 1);
            if (dec <= k && s[i] == '1')
                ans++;
        }
        return ans;
    }
};