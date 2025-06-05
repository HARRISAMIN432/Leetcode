class Solution {
public:
    int trap(vector<int>& height) {
        int maxIndex = 0, maxValue = 0, maxi = height[0], ans = 0;
        for(int i = 0; i < height.size(); i++) 
            if(height[i] > maxValue) {
                maxIndex = i;
                maxValue = height[i];
            }
        for(int i = 1; i < maxIndex; i++) {
            maxi = max(maxi, height[i]);
            ans += min(maxi, maxValue) - height[i];
        }
        maxi = height[height.size() - 1];
        for(int i = height.size() - 2; i > maxIndex; i--) {
            maxi = max(maxi, height[i]);
            ans += min(maxi, maxValue) - height[i];
        }
        return ans;
    }
};