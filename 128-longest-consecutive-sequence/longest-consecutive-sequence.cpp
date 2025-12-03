class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> us;
        unordered_set<int> used;
        used.reserve(2 * nums.size());
        us.reserve(2 * nums.size());
        for(int &x : nums) us.insert(x);
        int ans = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(us.find(nums[i] - 1) == us.end() && used.find(nums[i]) == used.end()) {
                int size = 1, curr = nums[i];
                used.insert(curr);
                while(us.find(curr + 1) != us.end()) 
                    size++, curr++;
                ans = max(ans, size);
            }
        }
        return ans;
    }
};