class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(201, 0);
        int mx = 1;
        for(int x : nums) {
            if(x > mx) mx = x;
            freq[x]++;
        }
        if(freq[mx] != 2) return false;
        for(int i = 1; i < mx; i++) if(freq[i] != 1) return false;
        return true;
    }
};