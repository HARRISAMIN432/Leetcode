class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0), sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        vector<int> o;
        int ans = 0, req = abs(sum2 - sum1);
        if(sum1 == sum2) return 0;
        else if(sum1 > sum2) {
            for(int i = 0; i < nums2.size(); i++) o.push_back(6 - nums2[i]);
            for(int i = 0; i < nums1.size(); i++) o.push_back(nums1[i] - 1);
        }
        else {
            for(int i = 0; i < nums1.size(); i++) o.push_back(6 - nums1[i]);
            for(int i = 0; i < nums2.size(); i++) o.push_back(nums2[i] - 1);
        }
        sort(o.rbegin(), o.rend());
        for(int i = 0; i < o.size(); i++) {
                req -= o[i];
                if(req <= 0) return i + 1;
            }
        return -1;
    }
};