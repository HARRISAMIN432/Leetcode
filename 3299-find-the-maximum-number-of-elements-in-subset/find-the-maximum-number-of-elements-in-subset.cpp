class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        unordered_set<int> vis;
        int ans = count(nums.begin(), nums.end(), 1);
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(x == 1) continue;
            if(vis.find(x) != vis.end()) continue;
            vis.insert(x);
            for(int j = 1, c = 1; j < INT_MAX; j *= 2, c++) {
                long long nextP = pow(x, j);
                if(nextP > INT_MAX) {
                    ans = max(ans, (c - 1) * 2 - 1);
                    break;
                }
                if(mp[nextP] == 0) {
                    ans = max(ans, (c - 1) * 2 - 1);
                    break;
                }
                else if(mp[nextP] == 1) {
                    ans = max(ans, c * 2 - 1);
                    break;
                }
            }
        }
        return ans % 2 == 0 ? --ans : ans;
    }
};