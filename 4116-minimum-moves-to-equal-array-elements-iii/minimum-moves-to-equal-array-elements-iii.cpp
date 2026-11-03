class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxE = nums[n - 1];
        int moves = 0;
        for (auto x : nums) {
            moves = moves + (maxE - x);
        }
        return moves;
    }
};