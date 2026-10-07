class Solution {
public:
    unordered_set<string> st;

    void dfs(string &s, int index, int leftRemove, int rightRemove,
             int balance, string curr) {

        if (index == s.length()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                st.insert(curr);
            }
            return;
        }

        char ch = s[index];

        // Remove current character
        if (ch == '(' && leftRemove > 0) {
            dfs(s, index + 1, leftRemove - 1, rightRemove,
                balance, curr);
        }

        if (ch == ')' && rightRemove > 0) {
            dfs(s, index + 1, leftRemove, rightRemove - 1,
                balance, curr);
        }

        // Keep current character
        if (ch != '(' && ch != ')') {
            dfs(s, index + 1, leftRemove, rightRemove,
                balance, curr + ch);
        }
        else if (ch == '(') {
            dfs(s, index + 1, leftRemove, rightRemove,
                balance + 1, curr + ch);
        }
        else {
            if (balance > 0) {
                dfs(s, index + 1, leftRemove, rightRemove,
                    balance - 1, curr + ch);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(st.begin(), st.end());
    }
};