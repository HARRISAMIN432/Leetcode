class Solution {
public:
    int numSquares(int n) {
        int i = 1, ans = INT_MAX;
        vector<int> sq;
        while(i * i <= n) {
            sq.push_back(i * i);
            i++;
        } 
        unordered_set<int> dp;
        queue<pair<int, int>> q;
        q.push({n, 0});
        while(!q.empty()) {
            int num = q.front().first, lvl = q.front().second;
            q.pop();
            if(dp.find(num) != dp.end() || lvl > ans) continue;
            dp.insert(num);
            i = 0;
            while(i < sq.size() && sq[i] <= num) {
                if(sq[i] == num) {
                    ans = min(ans, lvl + 1);
                    break;
                }
                q.push({num - sq[i], lvl + 1});
                i++;
            }
        }
        return ans;
    }
};