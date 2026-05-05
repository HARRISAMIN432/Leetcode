class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int a = 1, b = 1;
        for(int i = 1; i < s.size(); i++) {
            int ways = 0;
            if(s[i] != '0') ways += b;
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                ways += a;
            a = b, b = ways;
        }
        return b;
    }
};