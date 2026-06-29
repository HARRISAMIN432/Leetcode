class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int ans = accumulate(piles.begin(), piles.end(), 0);
        while(k--) {
            int x = pq.top(), rem = x / 2; pq.pop();
            ans -= (rem);
            pq.push(x - rem);
        }
        return ans;
    }
};