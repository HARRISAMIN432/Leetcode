class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2)
            return 0;
        stack<int> idx;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == '(' && s[i] == ')') {
                st.pop();
                idx.pop();
            } else {
                st.push(s[i]);
                idx.push(i);
            }
        }
        if(idx.size() == 0) return s.size();
        int ans = 0, num1 = (int)s.size();
        while(!idx.empty()) {
            int num2 = idx.top();
            idx.pop();
            ans = max(ans, num1 - num2 - 1);
            num1 = num2;
        }
        return max(ans, num1);
    }
};