class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> subarrays;

        // Step 1: Generate all subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            vector<int> sub1;

            for (int j = i; j < i + k; j++) {
                sub1.push_back(nums[j]);
            }

            subarrays.push_back(sub1);
        }

        // Step 2: Count in how many subarrays each element occurs
        vector<int> freq(51, 0);

        for (auto sub : subarrays) {

            // Duplicate element in same subarray should count only once
            set<int> st;

            for (int x : sub) {
                st.insert(x);
            }

            for (int x : st) {
                freq[x]++;
            }
        }

        // Step 3: Find largest element occurring in exactly one subarray
        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            if (freq[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};