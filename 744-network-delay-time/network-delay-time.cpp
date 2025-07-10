class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d > dist[node]) continue;
            for(int i = 0; i < times.size(); i++) 
                if(times[i][0] == node && d + times[i][2] < dist[times[i][1]]) {
                    dist[times[i][1]] = d + times[i][2];
                    pq.push({dist[times[i][1]], times[i][1]});
                }
        }
        for(int i = 1; i <= n; i++) 
            if(dist[i] == INT_MAX) return -1;
        return *max_element(dist.begin() + 1, dist.end());
    }
};