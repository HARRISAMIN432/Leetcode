class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i, leftE = i, rightE = i + 1;
            while (right < s.size() && left >= 0 && s[right] == s[left]) 
                left--, right++;
            while (rightE < s.size() && leftE >= 0 && s[rightE] == s[leftE])
                leftE--, rightE++;
            if(right - left - 1 > ans.size()) ans = s.substr(left + 1, right - left - 1);
            if(rightE - leftE - 1 > ans.size()) ans = s.substr(leftE + 1, rightE - leftE - 1);
        }
        return ans;
    }
};