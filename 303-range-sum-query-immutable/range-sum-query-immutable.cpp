class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->prefix.reserve(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) prefix[i] = prefix[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return !left ? prefix[right] : prefix[right] - prefix[left - 1];
    }

private:
    vector<long long> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */