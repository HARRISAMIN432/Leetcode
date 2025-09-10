class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int p = 0;
        for(int i = 0; i < nums.size(); i++) 
            if(nums[i] < pivot) less.push_back(nums[i]);
            else if(nums[i] > pivot) greater.push_back(nums[i]);
            else p++;
        for(int i = 0; i < less.size(); i++) nums[i] = less[i];
        for(int i = 0; i < p; i++) nums[i + less.size()] = pivot;
        for(int i = 0; i < greater.size(); i++) nums[i + less.size() + p] = greater[i];
        return nums;
    }
};