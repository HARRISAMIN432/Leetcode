class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> dist;
        for(int i = 0; i < arr.size(); i++) 
            dist.push_back({abs(arr[i] - x), arr[i]});
        sort(dist.begin(), dist.end());
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(dist[i].second);
        sort(ans.begin(), ans.end());
        return ans;
    }
};