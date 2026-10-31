
class Solution {
public:
    const int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dir: 0 = Right, 1 = Down
        // memo stores final destination of a move
        vector<vector<array<int, 2>>> memo(m,
                                           vector<array<int, 2>>(n, {-2, -2}));

        // Returns destination cell index, -1 if invalid
        function<int(int, int, int)> getDest = [&](int r, int c,
                                                   int dir) -> int {
            if (memo[r][c][dir] != -2)
                return memo[r][c][dir];

            int nr = r;
            int nc = c;

            if (dir == 0)
                nc++;
            else
                nr++;

            // Out of bounds
            if (nr >= m || nc >= n)
                return memo[r][c][dir] = -1;

            // Empty cell: movement completed
            if (grid[nr][nc] == 0) {
                return memo[r][c][dir] = nr * n + nc;
            }

            // Mirror: change direction and continue
            return memo[r][c][dir] = getDest(nr, nc, 1 - dir);
        };

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = 1;

        // DP traversal
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                // Move Right
                int right = getDest(i, j, 0);

                if (right != -1) {
                    int x = right / n;
                    int y = right % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }

                // Move Down
                int down = getDest(i, j, 1);

                if (down != -1) {
                    int x = down / n;
                    int y = down % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
