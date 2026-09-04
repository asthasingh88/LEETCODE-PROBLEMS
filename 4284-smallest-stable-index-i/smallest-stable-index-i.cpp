class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;

            // 0 to i ka maximum
            for (int j = 0; j <= i; j++) {
                maxi = max(maxi, nums[j]);
            }

            // i to n-1 ka minimum
            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
            }

            int ins = maxi - mini;

            if (ins <= k)
                return i;
        }

        return -1;
    }
};