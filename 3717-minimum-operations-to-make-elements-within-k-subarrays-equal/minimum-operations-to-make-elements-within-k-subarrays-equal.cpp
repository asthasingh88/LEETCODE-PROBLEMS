
class Solution {
public:
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;

    void add(long long x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }

        balance();
    }

    void remove(long long x) {
        auto it = low.find(x);

        if (it != low.end()) {
            sumLow -= x;
            low.erase(it);
        } else {
            it = high.find(x);
            sumHigh -= x;
            high.erase(it);
        }

        balance();
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            long long x = *it;

            low.erase(it);
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            auto it = high.begin();
            long long x = *it;

            high.erase(it);
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    }

    long long getCost() {
        long long med = *low.rbegin();

        return med * (long long)low.size() - sumLow + sumHigh -
               med * (long long)high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};
