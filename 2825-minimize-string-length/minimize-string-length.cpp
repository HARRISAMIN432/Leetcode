class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> freq(26, 0);
        for(char c : s) freq[c - 'a'] = 1;
        int ans = 0;
        for(int i = 0; i < 26; i++) if(freq[i]) ans++;
        return ans;
    }
};