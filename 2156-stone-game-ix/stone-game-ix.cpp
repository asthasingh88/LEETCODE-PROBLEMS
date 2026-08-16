class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0};

        // Count remainders
        for(int x : stones) {
            cnt[x % 3]++;
        }

        // Case 1: number of remainder-0 stones is even
        if(cnt[0] % 2 == 0) {
            return min(cnt[1], cnt[2]) > 0;
        }

        // Case 2: number of remainder-0 stones is odd
        return abs(cnt[1] - cnt[2]) > 2;
    }
};