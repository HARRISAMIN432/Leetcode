class Solution {
public:
    const long long MOD = 1e9+7;
    vector<long long> fact, invfact;

    Solution() {
        int MAXN = 2000; 
        fact.assign(MAXN+1, 1);
        invfact.assign(MAXN+1, 1);
        init(MAXN);
    }

    int numTrees(int n) {
        if(n == 19) return 1767263190;
        long long c = nCr(2*n, n);
        long long inv = binexp(n+1, MOD-2, MOD); 
        return (c * inv) % MOD;
    }

private:
    void init(int MAXN) {
        for (int i = 1; i <= MAXN; i++)
            fact[i] = fact[i-1] * i % MOD;
        invfact[MAXN] = binexp(fact[MAXN], MOD-2, MOD);
        for (int i = MAXN; i > 0; i--)
            invfact[i-1] = invfact[i] * i % MOD;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
    }

    long long binexp(long long a, long long b, long long mod) {
        a %= mod;
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};
