class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = INT_MAX, mx = -1;
        for(long long n : nums) mn = min(mn, n), mx = max(mx, n);
        return 1LL * (mx - mn) * k;
    }
};