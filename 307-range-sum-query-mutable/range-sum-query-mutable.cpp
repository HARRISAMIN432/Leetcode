struct SegTree {
    int n;
    vector<long long> st;

    SegTree(int n) {
        this->n = n;
        st.assign(4 * n, 0);
    }

    void build(int node, int l, int r, vector<long long> &a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node * 2 + 1, l, mid, a);
        build(node * 2 + 2, mid + 1, r, a);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            st[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(node * 2 + 1, l, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, r, idx, val);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return st[node];
        int mid = (l + r) >> 1;
        return query(node * 2 + 1, l, mid, ql, qr) +
               query(node * 2 + 2, mid + 1, r, ql, qr);
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) : st(nums.size()), n(nums.size()) {
        vector<long long> a(nums.begin(), nums.end());
        st.build(0, 0, n - 1, a);
    }

    void update(int index, int val) {
        st.update(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return st.query(0, 0, n - 1, left, right);
    }

private:
    SegTree st;
    int n;
};
