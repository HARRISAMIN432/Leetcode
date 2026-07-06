class Solution {
    using ll = long long;

public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        while(k--) {
            ll n = pq.top();
            pq.pop();
            pq.push(n + 1);
        }
        ll ans = 1, MOD = 1e9 + 7;
        while(!pq.empty()) {
            ll n = pq.top();
            pq.pop();
            ans = ((ans % MOD) * (n % MOD)) % MOD;
        }
        return ans;
    }
};