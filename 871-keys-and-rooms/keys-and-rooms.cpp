class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, unordered_set<int>& ans, vector<bool>& visited) {
        visited[node] = 1;
        ans.insert(node);
        for(int neighbor : graph[node]) 
            if(!visited[neighbor]) dfs(neighbor, graph, ans, visited);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> graph(rooms.size());
        for (int i = 0; i < rooms.size(); i++)
            for (int j = 0; j < rooms[i].size(); j++)
                graph[i].push_back(rooms[i][j]);
        vector<bool> visited(rooms.size(), 0);
        unordered_set<int> ans;
        dfs(0, graph, ans, visited);
        for(int i = 0; i < rooms.size(); i++) 
            if(ans.find(i) == ans.end()) return false;
        return true;
    }
};