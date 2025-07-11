class Solution {
public:
    void helper(int node, vector<vector<int>>& graph, vector<int>& temp, vector<vector<int>>& ans) {
        if(node == graph.size() - 1) {
            ans.push_back(temp);
            return;
        }
        for(int neighbor : graph[node]) {
            temp.push_back(neighbor);
            helper(neighbor, graph, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;
        temp.push_back(0);
        helper(0, graph, temp, ans);
        return ans;
    }
};