class Solution {
public:
    int maxDistinct(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        int ans = 0;
        for(int i = 0; i < 26; i++) if(freq[i]) ans++;
        return ans;
    }
};