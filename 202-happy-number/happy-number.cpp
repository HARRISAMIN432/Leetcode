class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end()) {
            s.insert(n);
            int tmp = n, ans = 0;
            while(tmp > 0) {
                ans += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            if (ans == 1) return true;
            n = ans;
        }
        return false;
    }

private: 
    
};