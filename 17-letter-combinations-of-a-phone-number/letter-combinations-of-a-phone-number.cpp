class Solution {
public:
    void helper(int idx, string& digits, unordered_map<char, vector<char>>& map, string& temp, vector<string>& ans) {
        if(idx == digits.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < map[digits[idx]].size(); i++) {
            temp.push_back(map[digits[idx]][i]);
            helper(idx + 1, digits, map, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string temp;
        vector<string> ans;
        unordered_map<char, vector<char>> map;
        int alphabets = 97;
        for(int i = 2; i <= 9; i++) {
            char c = i + '0';
            int limit = (i != 7 && i != 9) ? 3 : 4;
            for(int j = 0; j < limit; j++)
            map[c].push_back(alphabets++);
        }
        helper(0, digits, map, temp, ans);
        return ans;
    }
};