class Solution {
public:
    int countOdds(int low, int high) {
            return (low & 1 || high & 1) ? (high - low) / 2 + 1 : (high - low) / 2;
    }
};