class Solution {
public:
    vector<vector<int>> g;
    vector<int> parent, depth, heavy, head, pos, sz;
    int curPos = 0;

    struct SegTree {
        int n;
        vector<int> st;

        SegTree(int N = 0) {
            n = N;
            st.assign(4 * n, 0);
        }

        void build(int p, int l, int r, vector<int>& arr) {
            if (l == r) {
                st[p] = arr[l];
                return;
            }

            int m = (l + r) >> 1;

            build(p << 1, l, m, arr);
            build(p << 1 | 1, m + 1, r, arr);

            st[p] = st[p << 1] ^ st[p << 1 | 1];
        }

        void update(int p, int l, int r, int idx, int val) {
            if (l == r) {
                st[p] = val;
                return;
            }

            int m = (l + r) >> 1;

            if (idx <= m)
                update(p << 1, l, m, idx, val);
            else
                update(p << 1 | 1, m + 1, r, idx, val);

            st[p] = st[p << 1] ^ st[p << 1 | 1];
        }

        int query(int p, int l, int r, int i, int j) {
            if (r < i || l > j)
                return 0;

            if (i <= l && r <= j)
                return st[p];

            int m = (l + r) >> 1;

            return query(p << 1, l, m, i, j) ^
                   query(p << 1 | 1, m + 1, r, i, j);
        }
    };

    SegTree seg;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;

        int maxSub = 0;

        for (int v : g[u]) {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;

            int sub = dfs(v, u);

            sz[u] += sub;

            if (sub > maxSub) {
                maxSub = sub;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = curPos++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : g[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            decompose(v, v);
        }
    }

    int pathQuery(int a, int b) {
        int res = 0;

        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]])
                swap(a, b);

            res ^= seg.query(1, 0, curPos - 1, pos[head[a]], pos[a]);

            a = parent[head[a]];
        }

        if (depth[a] > depth[b])
            swap(a, b);

        res ^= seg.query(1, 0, curPos - 1, pos[a], pos[b]);

        return res;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        g.assign(n, {});

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);

        dfs(0, -1);
        decompose(0, 0);

        vector<int> base(n);

        for (int i = 0; i < n; i++) {
            base[pos[i]] = 1 << (s[i] - 'a');
        }

        seg = SegTree(n);
        seg.build(1, 0, n - 1, base);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);

            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;

                ss >> u >> c;

                s[u] = c;

                seg.update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v);

                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return ans;
    }
};