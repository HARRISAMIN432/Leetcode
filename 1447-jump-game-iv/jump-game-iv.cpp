class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i]].push_back(i);
        queue<pair<int,int>> q;
        vector<bool> vis(arr.size(), false);
        q.push({0, 0});
        vis[0] = true;
        while(!q.empty()) {
            auto [steps, idx] = q.front();
            q.pop();
            if(idx == arr.size() - 1) return steps;
            for(int nxt : mp[arr[idx]]) {
                if(!vis[nxt]) {
                    vis[nxt] = true;
                    q.push({steps + 1, nxt});
                }
            }
            mp[arr[idx]].clear();
            if(idx + 1 < arr.size() && !vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({steps + 1, idx + 1});
            }
            if(idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({steps + 1, idx - 1});
            }
        }
        return -1;
    }
};