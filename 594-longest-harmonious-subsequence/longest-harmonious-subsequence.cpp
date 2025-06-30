class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num : nums) m[num]++;
        int ans = 0;
        for(int num: nums) {
            if(m.find(num + 1) != m.end()) ans = max(ans, m[num] + m[num + 1]);
            if(m.find(num - 1) != m.end()) ans = max(ans, m[num] + m[num - 1]);
        }
        return ans;
    }
};