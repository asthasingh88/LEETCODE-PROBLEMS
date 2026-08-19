class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        // Store reserved seats using bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &it : mp) {

            int mask = it.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            // 2,3,4,5
            for (int j = 2; j <= 5; j++) {
                if (mask & (1 << j)) {
                    left = false;
                    break;
                }
            }

            // 4,5,6,7
            for (int j = 4; j <= 7; j++) {
                if (mask & (1 << j)) {
                    middle = false;
                    break;
                }
            }

            // 6,7,8,9
            for (int j = 6; j <= 9; j++) {
                if (mask & (1 << j)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};