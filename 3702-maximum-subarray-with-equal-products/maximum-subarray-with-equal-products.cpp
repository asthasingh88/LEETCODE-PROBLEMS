class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }
    int LCM(int a, int b) { return (a / GCD(a, b)) * b; }
    int prod(int a, int b) { return a * b; }
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int p = 1;
            int l = 1;
            int g = 0;
            for (int j = i; j < n; j++) {
                p *= nums[j];
                g = GCD(g, nums[j]);
                l = LCM(l, nums[j]);
                if (p > 25200)
                    break;
                if (p == g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};