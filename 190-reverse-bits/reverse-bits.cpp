class Solution {
public:
    int reverseBits(int n) {
        string bin = DecToBin(n);
        reverse(bin.begin(), bin.end());
        for(int i = bin.size(); i < 32; i++) bin += '0';
        reverse(bin.begin(), bin.end());
        reverse(bin.begin(), bin.end());
        return BinToDec(bin);
    }

private:
    string DecToBin(int n) {
        if(n == 0) return "0";
        string ans;
        while(n > 1) {
            int rem = n % 2;
            ans += (rem + '0');
            n /= 2;
        }
        ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int BinToDec(string s) {
        int ans = 0, power = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '1') 
                ans += pow(2, power);
            power++;
        }
        return ans;
    }
};