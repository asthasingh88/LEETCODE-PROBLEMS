class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        int i = 1;

        while(i < n && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(nums[i] == sum)
                sum++;
            else if(nums[i] > sum)
                break;
        }

        return sum;
    }
};