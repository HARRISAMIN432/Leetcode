class SegTree {
private:
    vector<int> tree;
    vector<int> heights;
    int n;

    int better(int i, int j, vector<int>& a) {
        if (i == -1)
            return j;
        if (j == -1)
            return i;
        if (a[i] == a[j])
            return min(i, j);
        return (a[i] > a[j]) ? i : j;
    }

    void build(int node, int start, int end, vector<int>& a) {
        if (start == end) {
            tree[node] = start;
            return;
        }
        int mid = (start + end) >> 1;
        build(node * 2 + 1, start, mid, a);
        build(node * 2 + 2, mid + 1, end, a);
        tree[node] = better(tree[node * 2 + 1], tree[node * 2 + 2], a);
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || l > end)
            return -1;
        if (start >= l && end <= r)
            return tree[node];
        int mid = (start + end) >> 1;
        int left = query(node * 2 + 1, start, mid, l, r);
        int right = query(node * 2 + 2, mid + 1, end, l, r);
        return better(left, right, heights);
    }

public:
    SegTree(vector<int>& a) {
        n = a.size();
        heights = a;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1, a);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);
        SegTree tree(heights);
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) {
                ans[i] = b;
                continue;
            }
            int low = b + 1, high = heights.size() - 1;
            while (low <= high) {
                int mid = (low + high) >> 1, x = tree.query(b + 1, mid);
                if (x != -1 && heights[x] > heights[a]) {
                    ans[i] = x;
                    high = mid - 1;
                } 
                else low = mid + 1;
            }
        }
        return ans;
    }
};