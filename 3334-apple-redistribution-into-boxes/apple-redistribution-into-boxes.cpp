class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int sumApples = accumulate(apple.begin(), apple.end(), 0);
        int sumCapacity = 0;
        for(int i = 0; i < capacity.size(); i++) {
            sumCapacity += capacity[i];
            if(sumCapacity >= sumApples) return i + 1;
        }
        return INT_MAX;
    }
};