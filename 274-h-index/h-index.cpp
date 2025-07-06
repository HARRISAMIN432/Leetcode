class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = nums.size() - 1; i >= 0; i--) 
            if(nums[i] >= nums.size() - i) ans++;
            else break;
        return ans;
    }
};