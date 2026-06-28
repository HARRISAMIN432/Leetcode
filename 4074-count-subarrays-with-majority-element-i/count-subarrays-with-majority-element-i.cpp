class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        for(int i = 1; i <= n; i++) {
            int left = 0, right = 0, cnt = 0;
            while(right < i) {
                if(nums[right] == target) cnt++;
                right++;
            }
            if(cnt > i / 2) ans++;
            left++, cnt -= (nums[left - 1] == target) ? 1 : 0;
            while(right < n) {
                if(nums[right] == target) cnt++;
                if(cnt > i / 2) ans++;
                left++, right++, cnt -= (nums[left - 1] == target) ? 1 : 0;
            }
        }
        return ans;
    }
};