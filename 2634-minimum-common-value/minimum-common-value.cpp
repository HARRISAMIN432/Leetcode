class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0, n = nums1.size(), m = nums2.size();
        while(p1 < n && p2 < m) {
            if(nums1[p1] == nums2[p2]) return nums1[p1];
            else if(nums1[p1] > nums2[p2]) p2++;
            else p1++;
        }
        return -1;
    }
};