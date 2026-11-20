class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<long long, int> dp;
        int ans = 1;

        for (long long x : nums) {
            int useX = dp[x - 1] + 1; // keep x
            int useXp1 = dp[x] + 1;   // change x -> x + 1

            dp[x] = max(dp[x], useX);
            dp[x + 1] = max(dp[x + 1], useXp1);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};