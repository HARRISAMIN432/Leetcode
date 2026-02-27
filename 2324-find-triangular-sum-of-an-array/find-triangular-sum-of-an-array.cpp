class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        while(true) {
            vector<int> temp;
            for(int i = 0; i < nums.size() - 1; i++) 
                temp.push_back((nums[i] + nums[i + 1]) % 10);
            if(temp.size() == 1) return temp[0];
            else nums = temp;
        }
        return -1;
    }
};