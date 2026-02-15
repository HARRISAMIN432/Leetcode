class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        bool carry = 0;
        for(int i = 0; i < max(a.size(), b.size()); i++) 
            if(i >= a.size() || i >= b.size()) 
                if(carry) 
                    if(i >= a.size()) 
                        if(b[i] == '0') ans += '1', carry = 0;
                        else ans += '0';
                    else 
                        if(a[i] == '0') ans += '1', carry = 0;
                        else ans += '0';
                else if(i >= a.size()) ans += b[i];
                else ans += a[i];
            else 
                if(a[i] == '0' && b[i] == '0') (carry) ? carry = 0, ans += '1' : ans += '0';
                else if(a[i] == '1' && b[i] == '0') (carry) ? ans += '0' : ans += '1';
                else if(a[i] == '0' && b[i] == '1') (carry) ? ans += '0' : ans += '1';
                else (carry) ? ans += '1' : ans += '0', carry = 1;
        if(carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};