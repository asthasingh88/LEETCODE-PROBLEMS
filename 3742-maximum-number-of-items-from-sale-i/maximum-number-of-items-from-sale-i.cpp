class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), m = INT_MAX;
        for (auto& it : items)
            m = min(m, it[1]);

        vector<int> val(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0)
                    val[i]++;

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            for (int b = budget; b >= p; b--)
                dp[b] = max(dp[b], dp[b - p] + val[i]);
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++)
            ans = max(ans, dp[b] + (budget - b) / m);
        return ans;
    }
};
