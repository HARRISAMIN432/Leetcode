class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int ans = 0, left = 0, right = 0, maxi = 0;
        while (right < s.size()) {
            freq[s[right] - 'A']++;
            maxi = max(maxi, freq[s[right] - 'A']);
            if (maxi + k <= right - left) {
                ans = max(ans, right - left);
                freq[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        if (maxi + k <= right - left)
            ans = max(ans, right - left);
        if(left == 0) return s.size();
        return ans;
    }
};