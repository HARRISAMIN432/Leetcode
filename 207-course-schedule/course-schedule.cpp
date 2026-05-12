class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<int> inEdges(numCourses, 0);
        for(int i = 0; i < graph.size(); i++) 
            for(int j = 0; j < graph[i].size(); j++) inEdges[graph[i][j]]++;
        queue<int> q;
        for(int i = 0; i < inEdges.size(); i++) if(!inEdges[i]) q.push(i);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i = 0; i < graph[node].size(); i++) {
                inEdges[graph[node][i]]--;
                if(!inEdges[graph[node][i]]) {
                    q.push(graph[node][i]);
                }
            }
        }
        return (count(inEdges.begin(), inEdges.end(), 0) == numCourses) ? true : false;
    }
};