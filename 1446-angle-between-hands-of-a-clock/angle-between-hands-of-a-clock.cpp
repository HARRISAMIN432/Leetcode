class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double ha = (hour * 30) + (minutes * 0.5), ma = minutes * 6, angle = abs(ha - ma);
        return min(angle, 360 - angle);
    }
};