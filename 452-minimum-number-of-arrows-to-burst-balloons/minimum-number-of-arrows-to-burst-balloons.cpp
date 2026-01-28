class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int ans = 1, r = points[0][1];
        for(int i = 0; i < points.size(); i++) 
            if(points[i][0] > r) {
                ans++;
                r = points[i][1];
            }
        return ans;
    }
};