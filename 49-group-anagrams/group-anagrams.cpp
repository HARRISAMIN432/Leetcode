class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> visited(strs.size(), false);
        vector<vector<int>> freq(strs.size(), vector<int>(26, 0));
        for(int i = 0; i < strs.size(); i++) for(char c : strs[i]) freq[i][c - 'a']++;
        for(int i = 0; i < strs.size(); i++) {
            if(visited[i] == true) continue;
            vector<string> temp = {strs[i]};
            for(int j = i + 1; j < strs.size(); j++)  {
                if(visited[j] == true) continue;
                bool isSame = true;
                for(int k = 0; k < 26; k++) if(freq[i][k] != freq[j][k]) {
                    isSame = false;
                    break;
                }
                if(isSame) {
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};