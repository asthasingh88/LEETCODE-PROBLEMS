class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]); // add current element
                int distinctCount = st.size();
                ans += (long long)distinctCount * distinctCount; // square and add
            }
        }
        
        return (int)ans;
    }
};
