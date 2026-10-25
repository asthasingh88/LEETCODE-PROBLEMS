class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

        // Water
        if (grid[r][c] == 1)
            return;

        // Mark land as visited
        grid[r][c] = 1;

        // 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // Step 1: Remove land connected to left/right boundary
        for (int r = 0; r < rows; r++) {
            dfs(grid, r, 0);
            dfs(grid, r, cols - 1);
        }

        // Step 2: Remove land connected to top/bottom boundary
        for (int c = 0; c < cols; c++) {
            dfs(grid, 0, c);
            dfs(grid, rows - 1, c);
        }

        // Step 3: Count remaining islands
        int count = 0;

        for (int r = 1; r < rows - 1; r++) {
            for (int c = 1; c < cols - 1; c++) {

                if (grid[r][c] == 0) {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
};