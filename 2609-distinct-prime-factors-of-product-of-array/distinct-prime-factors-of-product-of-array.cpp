class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return 0;
        for(int i = 2; i <= pow(n, 0.5); i++) 
            if(n % i == 0) return false;
        return true;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        set<int> factors;
        for (int i = 0; i < nums.size(); i++) 
            for(int j = 1; j <= pow(nums[i], 0.5); j++) if(nums[i] % j == 0) {
                if(isPrime(j)) factors.insert(j);
                if(nums[i] / j != j && isPrime(nums[i] / j)) factors.insert(nums[i] / j); 
            }
        return factors.size();
    }
};