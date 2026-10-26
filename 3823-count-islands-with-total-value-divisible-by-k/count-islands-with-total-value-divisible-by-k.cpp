class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0 && !vis[i][j]) {

                    long long sum = 0;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    vis[i][j] = true;

                    while (!st.empty()) {
                        auto [r, c] = st.top();
                        st.pop();

                        sum += grid[r][c];

                        for (auto& [dr, dc] : dir) {
                            int nr = r + dr;
                            int nc = c + dc;

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] > 0 && !vis[nr][nc]) {

                                vis[nr][nc] = true;
                                st.push({nr, nc});
                            }
                        }
                    }

                    if (sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};