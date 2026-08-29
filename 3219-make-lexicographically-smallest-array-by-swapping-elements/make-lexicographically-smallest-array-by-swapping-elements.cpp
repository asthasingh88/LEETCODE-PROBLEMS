class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // {value, original index}
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort according to value
        sort(v.begin(), v.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {

            int end = start;

            // Find all elements belonging to the same group
            while (end + 1 < n &&
                   v[end + 1].first - v[end].first <= limit) {
                end++;
            }

            // Collect original indices
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(v[i].second);
            }

            // Smallest indices get smallest values
            sort(indices.begin(), indices.end());

            int j = 0;

            for (int i = start; i <= end; i++) {
                ans[indices[j++]] = v[i].first;
            }

            start = end + 1;
        }

        return ans;
    }
};