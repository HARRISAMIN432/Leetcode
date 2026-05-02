class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            string s = to_string(i);
            bool isgood = false;
            for(char c : s) {
                if(c == '3' || c == '4' || c == '7') {
                    isgood = false;
                    break;
                }
                if(c == '2' || c == '5' || c == '6' || c == '9') isgood = true;
            }
            if(isgood) ans++;
        }
        return ans;
    }
};