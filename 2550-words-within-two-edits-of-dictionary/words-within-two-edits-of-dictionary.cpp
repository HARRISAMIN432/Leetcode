class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i = 0; i < queries.size(); i++) {
            for(int j = 0; j < dictionary.size(); j++) {
                if(check(queries[i], dictionary[j]) <= 2) {
                    ans.push_back(queries[i]);
                    break; 
                }
            }
        }

        return ans;
    }

private:
    int check(string s, string t) {
        int diff = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) diff++;
        }
        return diff;
    }
};