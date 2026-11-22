class Solution {
public:
    bool checkString(string s) {
        int l = s.length();
        for (int i = 0; i + 1 < l; i++) {
            if (s[i] == 'b' && s[i + 1] == 'a')
                return false;
        }
        return true;
    }
};