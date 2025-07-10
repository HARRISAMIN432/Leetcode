class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights)
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if (stops > k) continue;
            for (auto& [nei, price] : graph[node]) {
                if (cost + price < minCost[nei]) {
                    minCost[nei] = cost + price;
                    q.push({stops + 1, {nei, cost + price}});
                }
            }
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
