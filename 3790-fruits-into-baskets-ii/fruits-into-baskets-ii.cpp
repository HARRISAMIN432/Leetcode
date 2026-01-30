struct SegTree {
    int n;
    vector<int> st, a;

    SegTree(vector<int>& nums) {
        this->n = nums.size();
        a = nums;
        st.resize(this->n * 4);
        build(0, 0, this->n - 1);
    }

    int build(int node, int l, int r) {
        if (l == r)
            return st[node] = l;
        int mid = (l + r) >> 1;
        int left = build(node * 2 + 1, l, mid);
        int right = build(node * 2 + 2, mid + 1, r);
        if (a[left] >= a[right])
            return st[node] = left;
        else
            return st[node] = right;
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return -1;
        if (l >= ql && r <= qr)
            return st[node];
        int mid = (l + r) >> 1;
        int left = query(node * 2 + 1, l, mid, ql, qr);
        int right = query(node * 2 + 2, mid + 1, r, ql, qr);
        if (left == -1)
            return right;
        else if (right == -1)
            return left;
        else if (a[left] >= a[right])
            return left;
        return right;
    }

    int update(int node, int l, int r, int idx) {
        if (l == r)
            return st[node] = l;
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2 + 1, l, mid, idx);
        else
            update(node * 2 + 2, mid + 1, r, idx);
        int left = st[node * 2 + 1];
        int right = st[node * 2 + 2];
        if (a[left] >= a[right])
            return st[node] = left;
        else
            return st[node] = right;
    }

    void update(int idx) {
        a[idx] = -1;
        update(0, 0, n - 1, idx);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegTree st(baskets);
        int ans = 0, n = fruits.size();
        for (int& fruit : fruits) {
            int low = 0, high = n - 1, idx = -1;
            while (low <= high) {
                int mid = (low + high) >> 1,
                    tmp = st.query(0, 0, n - 1, low, mid);
                if (st.a[tmp] >= fruit) {
                    idx = tmp;
                    high = mid - 1;
                } else
                    low = mid + 1;
            }
            if (idx == -1)
                ans++;
            else
                st.update(idx);
        }
        return ans;
    }
};