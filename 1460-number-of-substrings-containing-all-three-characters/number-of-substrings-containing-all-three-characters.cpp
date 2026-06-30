class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, l = 0, r = 0, cnt[3] = {0};
        while(r < s.size()) {
            cnt[s[r] - 'a']++;
            if(cnt[0] && cnt[1] && cnt[2]) {
                ans += s.size() - r;
                cnt[s[l] - 'a']--;
                l++;
                while(l <= r) {
                    if(cnt[0] && cnt[1] && cnt[2]) {
                        ans += s.size() - r;
                        cnt[s[l] - 'a']--;
                        l++;
                    }
                    else break;
                }
            }
            r++;
        }
        return ans;
    }
};