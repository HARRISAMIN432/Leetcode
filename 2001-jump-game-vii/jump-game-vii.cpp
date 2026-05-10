class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        set<int> zIdx;
        for(int i = 0; i < n; i++) 
            if(s[i] == '0')
                zIdx.insert(i);
        queue<int> q;
        q.push(0);
        zIdx.erase(0); 
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            if(i == n - 1) return true;
            int L = i + minJump;
            int R = min(i + maxJump, n - 1);
            auto it = zIdx.lower_bound(L);
            while(it != zIdx.end() && *it <= R) {
                int x = *it;
                if(x == n - 1) return true;
                q.push(x);
                it = zIdx.erase(it); 
            }
        }
        return false;
    }
};