class Solution {
public:
    int countEven(int num) {
        if(num == 1) return 0;
        int ans = 0;
        for(int i = 2; i <= num; i++) {
            int sum = 0, tmp = i;
            while(tmp) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            if(!(sum & 1)) ans++;
        }
        return ans;
    }
};