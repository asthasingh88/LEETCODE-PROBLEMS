class Solution {
public:

    struct Node {
        char lc, rc;   // left character, right character
        int pref;      // longest same-char prefix
        int suff;      // longest same-char suffix
        int mx;        // longest same-char substring
        int len;       // length of segment

        Node() {
            lc = rc = '#';
            pref = suff = mx = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.lc = a.lc;
        res.rc = b.rc;

        // Initially maximum is from either side
        res.mx = max(a.mx, b.mx);

        // Prefix
        res.pref = a.pref;

        // If entire left segment has same character
        // and boundary characters are same,
        // prefix can extend into right segment
        if (a.pref == a.len && a.rc == b.lc) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        // If entire right segment has same character
        // and boundary characters are same,
        // suffix can extend into left segment
        if (b.suff == b.len && a.rc == b.lc) {
            res.suff = b.len + a.suff;
        }

        // If boundary characters are same,
        // suffix of left + prefix of right can combine
        if (a.rc == b.lc) {
            res.mx = max(res.mx, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            tree[node].lc = s[l];
            tree[node].rc = s[l];

            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].mx = 1;
            tree[node].len = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            tree[node].lc = c;
            tree[node].rc = c;

            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].mx = 1;
            tree[node].len = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, c);
        }
        else {
            update(2 * node + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};