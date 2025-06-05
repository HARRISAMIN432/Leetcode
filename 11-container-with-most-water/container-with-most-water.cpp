class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while(left < right) {
            ans = max(ans, (right - left) * min(height[left], height[right]));
            (height[left] <= height[right]) ? left++ : right--;
        }
        return ans;
    }
};