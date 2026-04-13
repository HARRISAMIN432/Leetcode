class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        string a = decToBin(nums[0]), b = decToBin(nums[1]), c = decToBin(nums[2]);
        return max({binToDec(a + b + c), binToDec(a + c + b), binToDec(b + a + c), binToDec(b + c + a), binToDec(c + a + b), binToDec(c + b + a)});
    }

private:
    string decToBin(int n) {
        string ans;
        while(n) {
            int num = n % 2;
            n /= 2;
            ans += (num + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int binToDec(string s) {
        int ans = 0, power = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '1') ans += pow(2, power);
            power++;
        }
        return ans;
    }
};