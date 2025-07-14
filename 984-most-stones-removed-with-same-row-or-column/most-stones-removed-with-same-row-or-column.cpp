class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n, 1);         
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findPar(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findPar(parent[n]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet ds(20002);  
        unordered_set<int> nodesUsed;
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;  
            ds.unionBySize(row, col);
            nodesUsed.insert(row);
            nodesUsed.insert(col);
        }
        int components = 0;
        for (int node : nodesUsed)
            if (ds.findPar(node) == node)
                components++;
        return stones.size() - components;
    }
};
