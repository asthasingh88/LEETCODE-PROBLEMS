class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++)
            children[parent[i]].push_back(i);

        vector<int> newParent = parent, order, last(26, -1);
        order.reserve(n);

        function<void(int)> dfs = [&](int x) {
            order.push_back(x);
            int c = s[x] - 'a';
            int saved = last[c];
            if (x != 0 && saved != -1)
                newParent[x] = saved;
            last[c] = x;
            for (int ch : children[x])
                dfs(ch);
            last[c] = saved;
        };
        dfs(0);

        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            ans[newParent[x]] += ans[x];
        }
        return ans;
    }
};