class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<char> colors(graph.size(), '0');
        for (int i = 0; i < graph.size(); i++) {
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