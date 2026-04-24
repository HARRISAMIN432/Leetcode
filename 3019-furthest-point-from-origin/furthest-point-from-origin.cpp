class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL = 0, cntR = 0;
        for(char c : moves) 
            if(c == 'L') cntL++;
            else if(c == 'R') cntR++;
        int ans = 0;
        for(char c : moves) {
            if(c == 'L') ans--;
            else if(c == 'R') ans++;
            else if(cntL >= cntR) ans--;
            else ans++;
        }
        return abs(ans);
    }
};