
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long mod = 1e9 + 7;
        long long odd = 0, even = 1, ans = 0;
        int sum = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2 == 1) {
                ans = (ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};
