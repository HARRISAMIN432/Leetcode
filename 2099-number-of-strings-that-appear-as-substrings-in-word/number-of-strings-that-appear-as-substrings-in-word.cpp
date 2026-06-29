struct RollingHash {
    using ll = long long;

    static const ll mod1 = 1000000007;
    static const ll mod2 = 1000000009;
    static const ll base = 911382323;

    vector<ll> h1, h2, p1, p2;

    RollingHash(const string &s) {
        int n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * base % mod1;
            p2[i + 1] = p2[i] * base % mod2;

            h1[i + 1] = (h1[i] * base + s[i]) % mod1;
            h2[i + 1] = (h2[i] * base + s[i]) % mod2;
        }
    }

    pair<ll, ll> getHash(int l, int r) const { 
        ll x1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % mod1;
        if (x1 < 0) x1 += mod1;
        ll x2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % mod2;
        if (x2 < 0) x2 += mod2;
        return {x1, x2};
    }
};

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        RollingHash wh(word);
        for(string w : patterns) {
            if (w.size() > word.size()) continue;
            RollingHash ph(w);
            for(int i = 0; i < word.size() - w.size() + 1; i++) 
                if(wh.getHash(i, i + w.size() - 1) == ph.getHash(0, w.size() - 1)) {
                    ans++;
                    break;
                }
        }
        return ans;
    }
};