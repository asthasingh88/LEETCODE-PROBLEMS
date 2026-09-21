class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {

            vector<long long> newDp(k, 0);

            // Start a new subarray: [x]
            newDp[x % k]++;

            // Extend all previous subarrays
            for (int rem = 0; rem < k; rem++) {
                if (dp[rem] > 0) {
                    int newRem = (1LL * rem * x) % k;
                    newDp[newRem] += dp[rem];
                }
            }

            // All subarrays ending at current x
            for (int rem = 0; rem < k; rem++) {
                ans[rem] += newDp[rem];
            }

            dp = newDp;
        }

        return ans;
    }
};