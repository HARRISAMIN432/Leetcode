class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return i < n && j < m && i >= 0 && j >= 0;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while (!pq.empty()) {
            int distance = pq.top().first, r = pq.top().second.first,
                c = pq.top().second.second;
            pq.pop();
            if (distance > dist[r][c])
                continue;
            for (int i = 0; i < 4; i++) {
                int nr = r + rows[i];
                int nc = c + cols[i];
                if (isValid(nr, nc, n, m)) {
                    int edgeEffort = abs(heights[r][c] - heights[nr][nc]);
                    int maxEffort = max(distance, edgeEffort);
                    if (maxEffort < dist[nr][nc]) {
                        dist[nr][nc] = maxEffort;
                        pq.push({maxEffort, {nr, nc}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};