class Solution {
public:
    int minimumEffort(vector<vector<int>>& t) {
        int n = t.size();
        sort(t.begin(), t.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        long long low = 0, high = INT_MAX, ans = 0;
        while(low <= high) {
            long long mid = (low + high) >> 1, temp = mid;
            bool done = true;
            for(int i = 0; i < n; i++) {
                if(t[i][1] <= temp) 
                    temp -= t[i][0];
                else {
                    done = false;
                    break;
                }
            } 
            if(done) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};