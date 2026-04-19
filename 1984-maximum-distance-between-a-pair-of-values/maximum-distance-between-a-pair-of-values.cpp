class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++) {
            int low = i, high = nums2.size() - 1, mid, tmp = -1;
            while(low <= high) {
                mid = (low + high) >> 1;
                if(nums2[mid] >= nums1[i]) {
                    tmp = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            if(tmp != -1) ans = max(ans, tmp - i);
        }
        return ans;
    }
};