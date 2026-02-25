class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt = countDigits(n);
        for (int i = 0; i <= 30; i++) {
            int power = 1 << i;
            if (cnt == countDigits(power))
                return true;
        }
        return false;
    }

private:
    vector<int> countDigits(int x) {
        vector<int> cnt(10, 0);
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    }
};