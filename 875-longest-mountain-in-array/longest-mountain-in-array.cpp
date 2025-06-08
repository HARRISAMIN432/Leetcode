class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3) return 0;
        int maxi = 0;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1, right = i + 1, size = 3;
                while (left > 0 && arr[left] > arr[left - 1]) {
                    size++;
                    left--;
                }
                while (right < arr.size() - 1 && arr[right] > arr[right + 1]) {
                    size++;
                    right++;
                }
                maxi = max(size, maxi);
            }
        }
        return maxi;
    }
};