class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> vis(n, false);
        vis[0] = true;
        long long d = f(0, graph, vis);
        return modPow(2, d - 1);
    }

private:
    const long long MOD = 1e9 + 7;

    int f(int x, vector<vector<int>>& graph, vector<bool>& vis) {
        int ans = 0;
        for (int nei : graph[x]) {
            if (!vis[nei]) {
                vis[nei] = true;
                ans = max(ans, 1 + f(nei, graph, vis));
            }
        }
        return ans;
    }

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
};