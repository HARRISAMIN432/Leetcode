class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<pair<int, int>> a(nums.size());
        for(int i = 0; i < nums.size(); i++) a[i] = make_pair(nums[i], i);
        stable_sort(a.begin(), a.end());
        int ans = INT_MAX;
        for(int i = 0; i + 2 < a.size(); i++) 
            if(a[i].first == a[i + 1].first && a[i + 1].first == a[i + 2].first) 
                ans = min(ans, 2 * (a[i + 2].second - a[i].second));
        return (ans == INT_MAX) ? -1 : ans;
    }
};