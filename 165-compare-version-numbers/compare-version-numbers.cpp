class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> a = split(v1), b = split(v2);
        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            int x = (i < a.size()) ? a[i] : 0;
            int y = (i < b.size()) ? b[i] : 0;
            if (x < y) return -1;
            if (x > y) return 1;
        }
        return 0;
    }

private:
    vector<int> split(string s) {
        vector<int> res;
        string cur;
        for (char c : s) {
            if (c == '.') {
                res.push_back(stoi(cur));
                cur.clear();
            } else {
                cur += c;
            }
        }
        res.push_back(stoi(cur));
        return res;
    }
};
