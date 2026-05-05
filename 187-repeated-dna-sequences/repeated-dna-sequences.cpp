class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10) return {};
        unordered_map<string, int> mp;
        vector<string> ans;
        string tmp;
        for(int i = 0; i < 10; i++) tmp += s[i];
        mp[tmp] = 1;
        for(int i = 10; i < s.size(); i++) {
            tmp.erase(0, 1);
            tmp.push_back(s[i]);
            mp[tmp]++;
            if(mp[tmp] == 2) ans.push_back(tmp);
        }
        return ans;
    }
};