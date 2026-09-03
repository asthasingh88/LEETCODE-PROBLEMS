class Solution {
public:
    bool correct(int x) {
        return x % 2 == 0;
    }

    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int minOdd = INT_MAX;

        // minimum odd number find karo
        for (int i = 0; i < n; i++) {
            if (!correct(nums1[i])) {
                minOdd = min(minOdd, nums1[i]);
            }
        }

        // Agar koi even number minimum odd se chhota hai
        for (int i = 0; i < n; i++) {
            if (correct(nums1[i])) {
                if (minOdd != INT_MAX && nums1[i] < minOdd) {
                    return false;
                }
            }
        }

        return true;
    }
};