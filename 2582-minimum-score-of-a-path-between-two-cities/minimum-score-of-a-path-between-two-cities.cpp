class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<vector<int>>> graph;
        for(auto edge : roads) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto i : graph[node]) {
                ans = min(ans, i[1]);
                if(!vis[i[0]]) {
                    q.push(i[0]);
                    vis[i[0]] = true;
                }
            }
        }
        return ans;
    }    
};