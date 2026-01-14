class Solution {
public:
    string rle(string s) { 
        string ans;
        int c = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i - 1]) {
                ans += (c + '0');
                ans += s[i - 1];
                c = 0;
            }
            c++;
        }
        ans += (c + '0');
        return ans + s[s.size() - 1];
    }

    string countAndSay(int n) {
        if(n == 1) return "1";
        string a = "1";
        for(int i = 0; i < n - 1; i++) 
            a = rle(a);
        return a;
    }
};