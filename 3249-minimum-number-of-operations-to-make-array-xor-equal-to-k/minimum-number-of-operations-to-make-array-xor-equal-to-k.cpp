class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (int n : nums) x ^= n;
        int diff = x ^ k;
        return __builtin_popcount(diff);
    }
};
