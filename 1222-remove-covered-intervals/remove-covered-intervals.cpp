class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = intervals.size(), n = ans;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    ans--;
                    break;
                }
            }
        return ans;
    }
};