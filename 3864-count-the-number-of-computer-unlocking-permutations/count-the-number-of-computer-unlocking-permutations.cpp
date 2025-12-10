class Solution {
public:
    int countPermutations(vector<int>& c) {
        const int mod = 1000000007;
        long long fact = 1;
        for(int i = 1; i < c.size(); i++){
            if(c[i] <= c[0]){
                return 0;
            }
            fact *= i;
            fact %= mod;
        }
        return fact;
    }
};