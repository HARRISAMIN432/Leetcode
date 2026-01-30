struct SegTree {
    int n;
    vector<int> st, a;

    SegTree(vector<int>& nums) {
        this->n = nums.size();
        this->a = nums;
        this->st.resize(4 * this->n);
        build(0, 0, this->n - 1);
    }

    int build(int node, int l, int r) {
        if (l == r)
            return st[node] = l;
        int mid = (l + r) >> 1;
        int left = build(node * 2 + 1, l, mid);
        int right = build(node * 2 + 2, mid + 1, r);
        if (a[left] >= a[right])
            st[node] = left;
        else
            st[node] = right;
        return st[node];
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (r < ql || l > qr)
            return -1;
        if (ql <= l && r <= qr)
            return st[node];
        int mid = (l + r) >> 1;
        int left = query(2 * node + 1, l, mid, ql, qr);
        int right = query(2 * node + 2, mid + 1, r, ql, qr);
        if (left == -1) return right;
        if (right == -1) return left;
        return (a[left] >= a[right] ? left : right);
    }

};

class Solution {
    public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegTree st(heights);
        vector<int> ans;
        for (vector<int>& q : queries) {
            int left = min(q[0], q[1]), right = max(q[0], q[1]);
            if(left == right) ans.push_back(left);
            else if(heights[left] < heights[right]) ans.push_back(right);
            else {
                int low = right + 1, high = heights.size() - 1, idx = INT_MAX;
                while(low <= high) {
                    int mid = (low + high) >> 1;
                    int tmp = st.query(0, 0, heights.size() - 1, low, mid);
                    if(heights[tmp] > heights[left] && heights[tmp] > heights[right]) {
                        idx = min(idx, tmp);
                        high = mid - 1;
                    }
                    else low = mid + 1;
                }
                if(idx == INT_MAX) ans.push_back(-1);
                else ans.push_back(idx);
            }
        }
        return ans;
    }
};