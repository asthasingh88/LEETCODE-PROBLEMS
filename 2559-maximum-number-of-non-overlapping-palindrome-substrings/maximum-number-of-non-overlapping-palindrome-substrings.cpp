class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // isPal[l][r] = whether s[l...r] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r] &&
                    (len <= 2 || isPal[l + 1][r - 1])) {
                    isPal[l][r] = true;
                }
            }
        }

        // dp[i] = maximum number of palindromes
        // that can be selected from s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {

            // Don't use s[i] as the end of a palindrome
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Try every palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (isPal[i][j]) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};