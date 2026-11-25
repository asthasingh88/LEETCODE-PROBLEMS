class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        typedef unsigned long long ull;
        const ull B = 911382323ULL;

        auto hasUnique = [&](int L) {
            ull pw = 1;
            for (int i = 1; i < L; i++)
                pw *= B; // B^(L-1)

            unordered_map<ull, int> cnt;
            ull h = 0;
            for (int i = 0; i < n; i++) {
                if (i >= L)
                    h -= (ull)(nums[i - L] + 1000000007LL) * pw;
                h = h * B + (ull)(nums[i] + 1000000007LL);
                if (i >= L - 1)
                    cnt[h]++;
            }
            for (auto& [k, c] : cnt)
                if (c == 1)
                    return true;
            return false;
        };

        int lo = 1, hi = n; // hi = n always works
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (hasUnique(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};