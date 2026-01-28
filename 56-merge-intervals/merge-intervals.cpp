class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end()); 
        vector<vector<int>> res;
        for (auto &cur : intervals) 
            if (res.empty() || res.back()[1] < cur[0])
                res.push_back(cur);
            else
                res.back()[1] = max(res.back()[1], cur[1]);
        return res;
    }
};
