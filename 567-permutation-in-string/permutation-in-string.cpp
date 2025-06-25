class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(char c: s1) freq[c - 'a']++;
        for(int i = 0; i < s2.size(); i++) {
            int total = s1.size(), r = i;
            vector<int> temp = freq;
            while(r < s2.size() && temp[s2[r] - 'a'] > 0) {
                temp[s2[r] - 'a']--;
                total--;
                r++;
            }
            if(total == 0) return true;
        }
        return false;
    }
};