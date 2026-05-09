class RollingHash {
public:
    RollingHash(vector<int> &nums) {
        n = nums.size();
        powers.resize(n + 1, 1);
        hash.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            hash[i] = (hash[i - 1] * p + nums[i - 1]) % MOD;
            powers[i] = (powers[i - 1] * p) % MOD;
        }
    }

    int getHash(int l, int r) {
        long long res = (hash[r + 1] - (hash[l] * powers[r - l + 1])) % MOD;
        return (res + MOD) % MOD;
    }

private:
    const int MOD = 1e9 + 7;
    int n;
    int p = 131;

    vector<long long> powers;
    vector<long long> hash; 
};

class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        RollingHash hash1(n1), hash2(n2);
        int low = 1, high = n2.size(), ans = 0;
        while(low <= high) {
            int mid = (low + high) >> 1;
            bool found = false;
            for(int i = 0; i <= n1.size() - mid; i++) 
                for(int j = 0; j <= n2.size() - mid; j++) 
                    if(hash1.getHash(i, i + mid - 1) == hash2.getHash(j, j + mid - 1)) {
                        found = true;
                        break;
                    }
            if(found) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};