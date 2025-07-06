class FindSumPairs {
private:
    unordered_map<int, int> freq; 
    vector<int> nums1;
    vector<int> nums2;

public:
    FindSumPairs(vector<int>& n, vector<int>& mo) {
        nums1 = n;
        nums2 = mo;
        for (int x : nums2) freq[x]++;
    }

    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int b : nums1) {
            int a = tot - b;
            if (freq.count(a)) 
                ans += freq[a];
        }
        return ans;
    }
};
