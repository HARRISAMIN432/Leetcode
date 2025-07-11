class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start,
                          int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
       priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        pq.push({1.0, start});
        while (!pq.empty()) {
            double d = pq.top().first, node = pq.top().second;
            pq.pop();
            if (d < dist[node])
                continue;
            for (auto [neighbor, weight] : adj[node]) {
                if (dist[node] * weight > dist[neighbor]) {
                    dist[neighbor] = dist[node] * weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        if(dist[end] == INT_MIN) return -1;
        return dist[end];
    }
};