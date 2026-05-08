class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> scores(26, 0);
        for(int i = 0; i < 26; i++) {
            bool found = false;
            for(int j = 0; j < chars.size(); j++) 
                if(chars[j] == 'a' + i) {
                    found = true;
                    scores[i] = vals[j];
                    break;
                }
            if(!found) 
                scores[i] = i + 1;
        }
        int ans = INT_MIN, temp = 0;
        for(int i = 0; i < s.size(); i++) {
            temp += scores[s[i] - 'a']; 
            ans = max(ans, temp);
            if(temp < 0) 
                temp = 0;
        }
        return max(ans, 0);
    }
};