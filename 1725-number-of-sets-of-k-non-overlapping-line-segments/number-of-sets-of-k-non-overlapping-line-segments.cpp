class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> dp(n + k, 
                                     vector<long long>(2 * k + 1, 0));

        dp[0][0] = 1;

        // Calculate combinations:
        // C(n+k-1, 2k)
        int N = n + k - 1;
        int R = 2 * k;

        for (int i = 1; i <= N; i++) {
            dp[i][0] = 1;

            for (int j = 1; j <= R; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j <= i) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        return dp[N][R];
    }
};