class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int l = seq.length();
        int depth = 0;
        int i = 0;
        vector<int> ans(l);

        while (i < l) {
            if (seq[i] == '(') {
                depth++;

                if (depth % 2 == 1) {
                    ans[i] = 1;
                }
                else {
                    ans[i] = 0;
                }
            }
            else {
                if (depth % 2 == 1) {
                    ans[i] = 1;
                }
                else {
                    ans[i] = 0;
                }

                depth--;
            }

            i++;
        }

        return ans;
    }
};