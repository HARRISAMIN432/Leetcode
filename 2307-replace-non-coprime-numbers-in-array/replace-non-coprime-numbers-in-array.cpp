class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        for (int x : nums) {
            long long cur = x;
            while (!st.empty()) {
                long long top = st.top();
                long long g = gcd(top, cur);
                if (g == 1) break;
                st.pop();
                cur = (top / g) * cur;  
            }
            st.push(cur);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
