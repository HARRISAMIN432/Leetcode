class SegmentTree {
private:
    vector<long long> a;
    int n;

    void build(int node, int start, int end, vector<int> &nums) {
        if(start == end) {
            a[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);
        a[node] = a[node * 2 + 1] + a[node * 2 + 2];
    }

    void update(int node, int start, int end, int idx, int value) {
        if(start == end) {
            a[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if(mid >= idx) update(2 * node + 1, start, mid, idx, value);
        else update(2 * node + 2, mid + 1, end, idx, value);
        a[node] = a[node * 2 + 1] + a[node * 2 + 2];
    }

    long long query(int node, int start, int end, int l, int r) {
        if(r < start || l > end) return 0;
        if(start >= l && end <= r) return a[node];
        int mid = (start + end) / 2;
        long long left = query(node * 2 + 1, start, mid, l, r);
        long long right = query(node * 2 + 2, mid + 1, end, l, r);
        return left + right;
    }

public:
    SegmentTree(vector<int> &nums) {
        n = nums.size();
        a.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) : tree(nums) {}
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.query(left, right);
    }

private:
    SegmentTree tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */