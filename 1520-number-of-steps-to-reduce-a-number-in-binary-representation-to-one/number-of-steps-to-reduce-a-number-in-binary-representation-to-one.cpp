class Solution {
public:
    int numSteps(string s) {
        if(count(s.begin(), s.end(), '1') == 1 && s[s.size() - 1] == '1') return 0;
        int steps = 0;
        while(count(s.begin(), s.end(), '1') != 1 || s[s.size() - 1] != '1') {
            (s.back() == '1') ? addOne(s) : divideBy2(s);
            steps++;
        }
        return steps;
    }

private:
    void divideBy2(string &s) {
        string ans = "0";
        for(int i = 0; i < s.size() - 1; i++) ans += s[i];
        s = ans;
    }

    void addOne(string &s) {
        s[s.size() - 1] = '0';
        bool carry = 1;
        for(int i = s.size() - 2; i >= 0; i--) {
            if(carry) {
                if(s[i] == '1') s[i] = '0';
                else {
                    s[i] = '1';
                    carry = 0;
                }
            }
        }
        if(carry) s = "1" + s;
    }
};