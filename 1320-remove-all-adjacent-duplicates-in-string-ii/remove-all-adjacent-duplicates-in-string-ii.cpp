class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c : s) {
            if(!st.empty() && st.top().first == c) 
                if(st.top().second == k - 1) {
                    int i = st.top().second;
                    while(i--) st.pop();
                }
                else st.push({c, st.top().second + 1});
            else st.push({c, 1});
        }
        string ans;
        while(!st.empty()) {
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};