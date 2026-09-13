class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();

        vector<pair<int, int>> a, b;

        // Store positions of 1s in img1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});
            }
        }

        // Store positions of 1s in img2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;

        int ans = 0;

        // Try every pair of 1s
        for (auto p1 : a) {
            for (auto p2 : b) {

                int rowShift = p2.first - p1.first;
                int colShift = p2.second - p1.second;

                mp[{rowShift, colShift}]++;

                ans = max(ans, mp[{rowShift, colShift}]);
            }
        }

        return ans;
    }
};