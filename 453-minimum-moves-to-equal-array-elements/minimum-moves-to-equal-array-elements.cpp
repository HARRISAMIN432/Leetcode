class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, mini = INT_MAX;
        for(int num : nums) if(num < mini) mini = num;
        for(int num : nums) ans += num - mini;
        return ans;
    }
};