class Solution {
public:
    void generate(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int idx, int n) {
        if(idx == n) {
            ans.push_back(temp);
            return;
        }
        generate(nums,ans,temp,idx + 1, n);
        temp.push_back(nums[idx]);
        generate(nums,ans,temp,idx + 1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(nums,ans,temp,0,nums.size());
        return ans;
    }
};