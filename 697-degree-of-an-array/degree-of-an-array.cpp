class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> o(50001, {-1, -1});
        for(int i = 0; i < nums.size(); i++) {
            if(o[nums[i]].first == -1) o[nums[i]].first = i;
            o[nums[i]].second = i;
            freq[nums[i]]++;
        }
        int maxFreq = freq[nums[0]];
        for(auto it : freq) if(it.second > maxFreq) maxFreq = it.second;
        int ans = INT_MAX;
        for(int i = 0; i < 50001; i++) 
            if(freq[i] == maxFreq) ans = min(ans, o[i].second - o[i].first + 1);
        return ans;
    }
};