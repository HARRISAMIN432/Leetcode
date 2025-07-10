class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<char> colors(n + 1, '0');
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (colors[i] == '0') {
                q.push(i);
                colors[i] = 'R';
                while (!q.empty()) {
                    int node = q.front();
                    char color = colors[node];
                    q.pop();
                    for (int neighbor : graph[node]) {
                        if (colors[neighbor] == '0') {
                            if (color == 'R') {
                                q.push(neighbor);
                                colors[neighbor] = 'B';
                            } else {
                                q.push(neighbor);
                                colors[neighbor] = 'R';
                            }
                        } else if (colors[neighbor] == color) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};