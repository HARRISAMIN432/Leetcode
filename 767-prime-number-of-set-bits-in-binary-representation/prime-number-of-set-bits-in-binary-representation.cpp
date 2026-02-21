class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        int limit = sqrt(n);
        for(int i = 2; i <= limit; i++) if(n % i == 0) return false;
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) if(isPrime(__builtin_popcount(i))) ans++;
        return ans;
    }
};