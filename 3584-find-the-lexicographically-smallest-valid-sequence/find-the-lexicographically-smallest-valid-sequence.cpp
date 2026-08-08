class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = smallest index j in word2
        // that can be matched from word1[i...]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool mismatch = false;

        for (int i = 0; i < n && j < m; i++) {

            // Characters match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use this as the one mismatch
            else if (!mismatch && suf[i + 1] <= j + 1) {
                ans.push_back(i);
                j++;
                mismatch = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};