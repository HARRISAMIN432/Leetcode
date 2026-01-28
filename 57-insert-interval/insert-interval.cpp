class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int curL = intervals[0][0], curR = intervals[0][1];
        vector<vector<int>> res = {intervals[0]};
        for(int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if(l <= curR) 
                res.back()[1] = curR = max(r, res.back()[1]);
            else {
                curL = l, curR = r;
                res.push_back({l, r});
            }
        }
        return res;
    }
};