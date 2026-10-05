class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char ch : s) {
            if(ch == '(') {
                st.push(0);
            }
            else {
                int curr = st.top();
                st.pop();

                int val;

                if(curr == 0)
                    val = 1;
                else
                    val = 2 * curr;

                st.top() += val;
            }
        }

        return st.top();
    }
};