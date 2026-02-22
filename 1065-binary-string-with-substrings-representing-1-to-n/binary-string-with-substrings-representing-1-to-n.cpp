class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = 1; i <= n; i++) {
            int length = floor(log2(i)) + 1;
            bool found = false;
            for(int j = 0; j < s.size() - length + 1; j++) {
                if(binToDec(s.substr(j, length)) == i) {
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }

private:
    int binToDec(string s) {
        int ans = 0, power = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '1') ans += pow(2, power);
            power++;
        }
        return ans;
    }
};