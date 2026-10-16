class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum1 = 0, sum2 = 0, lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long v = val % MOD;

        tree[node].sum2 = (
            tree[node].sum2
            + 2 * v % MOD * tree[node].sum1 % MOD
            + len % MOD * v % MOD * v % MOD
        ) % MOD;

        tree[node].sum1 = (tree[node].sum1 + len * v) % MOD;
        tree[node].lazy = (tree[node].lazy + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        long long v = tree[node].lazy;

        apply(node * 2, l, mid, v);
        apply(node * 2 + 1, mid + 1, r, v);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node].sum1 = (
            tree[node * 2].sum1 + tree[node * 2 + 1].sum1
        ) % MOD;

        tree[node].sum2 = (
            tree[node * 2].sum2 + tree[node * 2 + 1].sum2
        ) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node].sum2;

        push(node, l, r);

        int mid = (l + r) / 2;
        return (
            query(node * 2, l, mid, ql, qr)
            + query(node * 2 + 1, mid + 1, r, ql, qr)
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i, 1);

            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};