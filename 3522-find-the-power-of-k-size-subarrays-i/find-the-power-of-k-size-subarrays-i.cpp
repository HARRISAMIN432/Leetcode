class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size() - k + 1; i++) {
            int maxi = nums[i];
            bool sorted = true;
            for(int j = i + 1; j < i + k; j++) {
                if(nums[j] != nums[j - 1] + 1) {
                    sorted = false;
                    break;
                }
                maxi = max(maxi, nums[j]);
            }
            if(!sorted) ans.push_back(-1);
            else ans.push_back(maxi);
        }
        return ans;
    }
};