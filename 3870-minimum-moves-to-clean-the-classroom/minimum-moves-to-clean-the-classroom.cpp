class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;

        vector<vector<int>> id(m, vector<int>(n, -1));
        int k = 0;

        // Find S and assign IDs to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                
                if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        // No litter
        if (k == 0)
            return 0;

        int fullMask = (1 << k) - 1;

        /*
            best[r][c][mask] =
            maximum energy with which we have reached
            (r,c) after collecting 'mask'
        */

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << k, -1)
            )
        );

        struct State {
            int r, c, mask, energy;
        };

        queue<State> q;

        best[sr][sc][0] = energy;

        q.push({sr, sc, 0, energy});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int en = cur.energy;

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // Cannot move without energy
                if (en == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = en - 1;
                    int newMask = mask;

                    // Collect litter
                    if (id[nr][nc] != -1) {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                        If we have already reached this
                        (r,c,mask) with MORE energy,
                        current state is useless.
                    */
                    if (newEnergy <= best[nr][nc][newMask])
                        continue;

                    best[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};