class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> inDegrees(n);
        for (int i = 0; i < prerequisites.size(); i++)
            inDegrees[prerequisites[i][0]]++;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (inDegrees[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(1);
            q.pop();
            for (int i = 0; i < prerequisites.size(); i++)
                if (prerequisites[i][1] == node) {
                    inDegrees[prerequisites[i][0]]--;
                    if (inDegrees[prerequisites[i][0]] == 0)
                        q.push(prerequisites[i][0]);
                }
        }
        return (ans.size() == n) ? true : false;
    }
};