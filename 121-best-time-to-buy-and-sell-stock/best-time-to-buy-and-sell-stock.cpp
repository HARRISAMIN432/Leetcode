class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], ans = INT_MIN;
        for(int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return (ans > 0) ? ans : 0;
    }
};