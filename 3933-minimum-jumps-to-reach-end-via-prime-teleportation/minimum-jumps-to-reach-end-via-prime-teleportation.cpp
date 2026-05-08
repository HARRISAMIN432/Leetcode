class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) 
            factors(nums[i], i);
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            int steps = pq.top().first, idx = pq.top().second;
            pq.pop();
            if(vis[idx]) continue;  
            vis[idx] = true;
            if(idx == n - 1) return steps;  
            if(isPrime(nums[idx])) {
                for(int i = 0; i < multiples[nums[idx]].size(); i++) {
                    int nxt = multiples[nums[idx]][i];
                    if(nxt != idx && nxt != idx+1 && nxt != idx-1 && !vis[nxt]) 
                        pq.push({steps + 1, nxt});
                }
                multiples[nums[idx]].clear(); 
            }

            if(idx + 1 < n && !vis[idx + 1]) 
                pq.push({steps + 1, idx + 1});

            if(idx - 1 >= 0 && !vis[idx - 1]) 
                pq.push({steps + 1, idx - 1});
        }
        return n - 1;
    }

private:
    unordered_map<int, vector<int>> multiples;

    void factors(int n, int idx) {
        int limit = sqrt(n);
        for(int i = 1; i <= limit; i++) {
            if(n % i == 0) {
                multiples[i].push_back(idx);
                int rest = n / i;
                if(rest != i) multiples[rest].push_back(idx);
            }
        }
    }      

    bool isPrime(int n) {
        if(n == 1) return false;
        int limit = sqrt(n);
        for(int i = 2; i <= limit; i++) 
            if(n % i == 0) return false;
        return true;
    }
};