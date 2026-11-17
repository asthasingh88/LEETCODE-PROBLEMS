
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute minimum changes for every substring
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int best = INT_MAX;

                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    for (int r = 0; r < d; r++) {
                        int l = i + r;
                        int right = i + len - d + r;

                        while (l < right) {
                            if (s[l] != s[right])
                                changes++;

                            l += d;
                            right -= d;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        // DP
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 2 * parts; i <= n; i++) {

                for (int t = 2 * (parts - 1); t <= i - 2; t++) {

                    if (dp[t][parts - 1] == INF)
                        continue;

                    dp[i][parts] =
                        min(dp[i][parts], dp[t][parts - 1] + cost[t][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
