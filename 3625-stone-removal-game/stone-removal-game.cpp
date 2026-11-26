class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;

        for (int k = 10; k >= 1 && n >= k; k--) {
            n = n - k;
            count++;
        }
        return count % 2 == 1;
    }
};