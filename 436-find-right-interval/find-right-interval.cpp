class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& ii) {
        vector<tuple<int, int, int>> ints;
        for(int i = 0; i < ii.size(); i++) ints.push_back(make_tuple(ii[i][0], ii[i][1], i));
        sort(ints.begin(), ints.end());
        vector<int> ans(ii.size());
        for(int i = 0; i < ints.size(); i++) {
            if(get<0>(ints[i]) == get<1>(ints[i])) {
                ans[get<2>(ints[i])] = (get<2>(ints[i]));
                continue;
            }
            int left = i + 1, right = ints.size() - 1, answer = -1;
            while(left <= right) {
                int mid = (left + right) >> 1;
                int start = get<0>(ints[mid]), idx = get<2>(ints[mid]), end = get<1>(ints[i]);
                if(start >= end) {
                    answer = idx;
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            ans[get<2>(ints[i])] = answer;
        }
        return ans;
    }
};