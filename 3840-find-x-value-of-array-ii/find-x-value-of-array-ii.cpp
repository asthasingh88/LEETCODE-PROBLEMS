class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> seg;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        // Product of complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes that cross from left into right
        for (int r = 0; r < k; r++) {
            int newRem = (a.prod * r) % k;
            res.cnt[newRem] += b.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {
            int rem = nums[l] % k;

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int value) {

        if (l == r) {
            int rem = value % k;

            seg[node].prod = rem;

            for (int i = 0; i < k; i++)
                seg[node].cnt[i] = 0;

            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, value);
        else
            update(node * 2 + 1, mid + 1, r, pos, value);

        seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        // Completely outside
        if (qr < l || r < ql) {
            return Node();
        }

        // Completely inside
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = l + (r - l) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->n = nums.size();
        this->k = k;

        seg.resize(4 * n + 5);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1, index, value);

            // Get all prefix products of nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};