/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* curr = head;
        while (curr) {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        int n = vec.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (vec[left] == vec[right]) {
                left++;
                right--;
            } else
                return false;
        }
        return true;
    }
};