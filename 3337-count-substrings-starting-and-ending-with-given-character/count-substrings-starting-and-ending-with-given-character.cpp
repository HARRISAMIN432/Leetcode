class Solution {
public:
    long long countSubstrings(string s, char c) {
       int tot = count_if(s.begin(), s.end(), [c](char x) { return x == c; });
       long long acc = 1, sum = 0;
       for(int i = 0; i < tot; i++) {
        sum += acc;
        acc++;
       } 
       return sum;
    }
};