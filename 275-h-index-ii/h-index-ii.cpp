class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1, ans = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(citations[mid] >= citations.size() - mid) {
                ans = citations.size() - mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};