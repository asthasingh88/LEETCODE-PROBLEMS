class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans = -1;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (!found) {
                    ans = nums[i];
                    found = true;
                } else {
                    ans &= nums[i];
                }
            }
        }

        return found ? ans : 0;
    }
};