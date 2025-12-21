class Solution {
public:
    long long countSubstrings(string s, char c) {
       long long t = count_if(s.begin(), s.end(), [c](char x) { return x == c; });
       return t * (t + 1) / 2;
    }
};