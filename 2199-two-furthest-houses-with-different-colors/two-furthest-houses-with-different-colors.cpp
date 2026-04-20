class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for(int i = 0; i < colors.size(); i++) {
            for(int j = colors.size() - 1; j >= i; j--) {
                if(colors[j] != colors[i]) ans = max(ans, abs(j - i));
            }
        }
        return ans;
    }
};