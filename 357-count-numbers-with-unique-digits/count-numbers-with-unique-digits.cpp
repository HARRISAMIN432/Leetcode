class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ans = 10, u = 9, av = 9;
        for (int len = 2; len <= n && av > 0; len++) {
            u *= av, ans += u, av--;
        }
        return ans;
    }
};