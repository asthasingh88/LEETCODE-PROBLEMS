class Solution {
public:

    struct Node {
        int l, r;
        long long w;
        int idx;
    };

    struct State {
        long long score;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;   // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<Node> v(n);

        for (int i = 0; i < n; i++) {
            v[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort according to starting point
        sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
            if (a.l != b.l)
                return a.l < b.l;

            if (a.r != b.r)
                return a.r < b.r;

            return a.idx < b.idx;
        });

        // next[i] = first interval whose l > current r
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            int lo = i + 1;
            int hi = n;

            while (lo < hi) {

                int mid = lo + (hi - lo) / 2;

                if (v[mid].l > v[i].r)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        // dp[i][k]
        // Starting from i, having already selected k intervals
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        // Base case:
        // dp[n][anything] = {0, {}}

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 0; k < 4; k++) {

                // ----------------
                // OPTION 1: SKIP
                // ----------------

                State skip = dp[i + 1][k];

                // ----------------
                // OPTION 2: TAKE
                // ----------------

                State take;

                take.score =
                    v[i].w + dp[nxt[i]][k + 1].score;

                take.ids = dp[nxt[i]][k + 1].ids;

                // Add original index
                take.ids.push_back(v[i].idx);

                // Final answer needs indices sorted
                sort(take.ids.begin(), take.ids.end());

                // Choose the better one
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][0].ids;
    }
};