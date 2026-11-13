
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        long long cost = 0, ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                int r = dq.back();
                dq.pop_back();

                int l = dq.empty() ? j + 1 : dq.back();

                cost += 1LL * (l - r) * (nums[i] - nums[r]);
            }

            dq.push_back(i);

            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];

                if (dq.front() == j)
                    dq.pop_front();

                j--;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
