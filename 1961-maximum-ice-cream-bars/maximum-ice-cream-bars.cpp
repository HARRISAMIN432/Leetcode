class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int c : costs) {
            if(c <= coins) {
                ans++;
                coins -= c;
            }
            else break;
        }
        return ans;
    }
};