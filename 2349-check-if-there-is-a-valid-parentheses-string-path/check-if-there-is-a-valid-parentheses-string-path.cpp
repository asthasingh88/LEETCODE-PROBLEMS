class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int bal, vector<vector<char>>& grid) {
        if (i >= m || j >= n) return false;

        if (grid[i][j] == '(')
            bal++;
        else
            bal--;

        if (bal < 0) return false;

        if (bal > (m - 1 - i) + (n - 1 - j))
            return false;

        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool down = solve(i + 1, j, bal, grid);
        bool right = solve(i, j + 1, bal, grid);

        return dp[i][j][bal] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n) % 2 == 0)
            return false;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n, -1)
        ));

        return solve(0, 0, 0, grid);
    }
};