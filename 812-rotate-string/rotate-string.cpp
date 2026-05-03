class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i <= s.size(); i++) {
            s.insert(s.begin(), s.back());
            s.pop_back();
            if(s == goal) return true;
        }
        return false;
    }
};