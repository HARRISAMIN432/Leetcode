class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> freq(words.size(), vector<int>(26, 0));
        for(int i = 0; i < words.size(); i++) for(char c : words[i]) freq[i][c - 'a']++;
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                bool isCommon = false;
                for(int k = 0; k < 26; k++) {
                    if(freq[i][k] && freq[j][k]) {
                        isCommon = true;
                        break;
                    }
                }
                if(!isCommon) ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
};