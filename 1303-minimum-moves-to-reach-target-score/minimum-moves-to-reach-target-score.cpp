class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while (target > 1) {
            if (maxDoubles == 0) return steps + (target - 1);
            if (target & 1) target--;
            else {
                target >>= 1;
                maxDoubles--;
            }
            steps++;
        }
        return steps;
    }
};