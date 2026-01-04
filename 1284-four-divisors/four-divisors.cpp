class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int x : nums) ans += calculateSumOfDivisors(x);
        return ans;
    }

private: 
    int calculateSumOfDivisors(int n) {
        vector<int> a;
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                a.push_back(i);
                if(n / i != i) a.push_back(n / i);
                if(a.size() > 4) return 0; 
            }
        }
        if(a.size() < 4) return 0;
        return a[0] + a[1] + a[2] + a[3];
    }
};