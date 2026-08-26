class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            // Window has exactly k ones
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {

                // Remove leading zeroes
                while (left <= right && s[left] == '0')
                    left++;

                string curr = s.substr(left, right - left + 1);

                // Shorter is better
                if (ans == "" || curr.size() < ans.size()) {
                    ans = curr;
                }
                // Same length -> lexicographically smaller
                else if (curr.size() == ans.size() && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};