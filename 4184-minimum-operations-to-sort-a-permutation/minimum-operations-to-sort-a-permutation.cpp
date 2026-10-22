class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Already sorted
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;

        // Case 1: nums is a rotation of [0,1,2,...,n-1]
        int k = nums[0];
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return min(n - k, k + 2);
        }

        // Case 2: nums is a rotation of [n-1,n-2,...,0]
        k = (n - 1 - nums[0] + n) % n;
        ok = true;

        for (int i = 0; i < n; i++) {
            int expected = (n - 1 - ((i + k) % n) + n) % n;

            if (nums[i] != expected) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return 1 + min(k, n - k);
        }

        return -1;
    }
};