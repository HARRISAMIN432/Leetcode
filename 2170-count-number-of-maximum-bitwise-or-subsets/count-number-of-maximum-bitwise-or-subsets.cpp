class Solution {
public:
    void subsets(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsets(idx + 1, nums, temp, ans);
        temp.pop_back();
        subsets(idx + 1, nums, temp, ans);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++) maxi = maxi | nums[i];
        vector<int> temp;
        vector<vector<int>> ans;
        int a = 0;
        subsets(0, nums, temp, ans);
        for(int i = 0; i < ans.size(); i++) {
            int tmp = 0;
            for(int j = 0; j < ans[i].size(); j++) 
                tmp |= ans[i][j];
            if(tmp == maxi) a++;
        }
        return a;
    }
};