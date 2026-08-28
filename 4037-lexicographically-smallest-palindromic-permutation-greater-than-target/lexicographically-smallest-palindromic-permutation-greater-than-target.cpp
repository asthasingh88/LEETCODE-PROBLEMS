class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // Check whether a palindromic permutation exists
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // halfCnt = number of each character available
        // in the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int h = n / 2;

        // We try to keep target's left half as long as possible.
        // If we can make it larger at position i, that gives
        // the smallest possible answer.
        vector<int> rem = halfCnt;

        // First, check whether target's left half itself can
        // be formed.
        bool possible = true;

        for (int i = 0; i < h; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
        }

        // If target's left half is possible, construct the
        // palindrome using it and check whether it is > target.
        if (possible) {
            string left = target.substr(0, h);

            string ans = left;

            if (n % 2)
                ans += mid;

            for (int i = h - 1; i >= 0; i--)
                ans += left[i];

            if (ans > target)
                return ans;
        }

        // Now find the rightmost position where we can increase
        // target's left half.
        rem = halfCnt;

        for (int i = 0; i < h; i++) {
            rem[target[i] - 'a']--;
        }

        // We don't necessarily have a valid exact target prefix,
        // so rebuild counts while moving from right to left.
        rem = halfCnt;

        for (int i = 0; i < h; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0)
                break;

            rem[x]--;
        }

        // Easier and safer: try every pivot from right to left.
        for (int i = h - 1; i >= 0; i--) {

            // Characters used by target[0 ... i-1]
            vector<int> available = halfCnt;

            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (available[x] == 0) {
                    ok = false;
                    break;
                }

                available[x]--;
            }

            if (!ok)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (available[c] == 0)
                    continue;

                available[c]--;

                string left = target.substr(0, i);
                left += char('a' + c);

                // Fill remaining positions with smallest chars
                for (int x = 0; x < 26; x++) {
                    left += string(available[x], char('a' + x));
                }

                string ans = left;

                if (n % 2)
                    ans += mid;

                for (int j = h - 1; j >= 0; j--)
                    ans += left[j];

                return ans;
            }
        }

        return "";
    }
};