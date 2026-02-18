class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool found = false, prev = true;
        for(int i = 30; i >= 0; i--) {
            int num = 1 << i;
            if((!(num & n)) && !found) continue;
            else if((!(num & n)) && found && !prev) return false;
            else if((num & n) && !found) found = true;
            else if((!(num & n)) && found && prev) prev = false;
            else if((num & n) && found && prev) return false;
            else if((num & n) && found && !prev) prev = true;
        }   
        return true;
    }
};