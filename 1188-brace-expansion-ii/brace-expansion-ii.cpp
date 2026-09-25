class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;

        set<string> result = solve(expression, pos);

        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> solve(string &s, int &pos) {
        set<string> result;
        set<string> current;
        current.insert("");

        while (pos < s.size() && s[pos] != '}') {

            if (s[pos] == ',') {
                result.insert(current.begin(), current.end());
                current.clear();
                current.insert("");
                pos++;
            }

            else if (s[pos] == '{') {
                pos++;

                set<string> inside = solve(s, pos);

                pos++;

                current = multiply(current, inside);
            }

            else {
                string word = "";

                while (pos < s.size() && isalpha(s[pos])) {
                    word += s[pos];
                    pos++;
                }

                set<string> temp;
                temp.insert(word);

                current = multiply(current, temp);
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    set<string> multiply(set<string> &a, set<string> &b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }
};