class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string temp;
        for(int i = 0; i < s.size(); i++) 
            if(s[i] != ' ') temp += s[i];
            else {
                ans.push_back(temp);
                temp = "";
            }
        ans.push_back(temp);
        string o;
        for(int i = 0; i < ans.size(); i++) {
            string t = ans[i];
            reverse(t.begin(), t.end());
            o += t;
            if(i != ans.size() - 1) o += ' ';
        }
        return o;
    }
};