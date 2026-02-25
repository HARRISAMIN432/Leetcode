class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        for(int &num : nums) freq[num]++;
        vector<vector<int>> ans;
        int size = 0;
        while(ans.size() == size) {
            vector<int> tmp;
            for(int i = 0; i < freq.size(); i++) 
                if(freq[i] > 0) {
                    tmp.push_back(i);
                    freq[i]--;
                }
            if(tmp.size() > 0) ans.push_back(tmp);
            size++;
        }
        return ans;
    }
};