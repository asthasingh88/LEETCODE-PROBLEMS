class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = nums[0];
        int moves = 0;
        for (int x : nums) {
            moves = moves + (x - mn);
        }
        return (int)moves;
    }
};