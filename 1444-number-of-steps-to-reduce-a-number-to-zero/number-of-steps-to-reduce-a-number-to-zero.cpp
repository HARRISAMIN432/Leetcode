class Solution {
public:
    int numberOfSteps(int target) {
        int steps = 0;
        while (target) {
            if(target & 1) target--;
            else target /= 2;
            steps++;
        }
        return steps;
    }
};