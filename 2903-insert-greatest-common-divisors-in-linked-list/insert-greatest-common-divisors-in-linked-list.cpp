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
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        else
            return GCD(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {

            int val = GCD(curr->val, curr->next->val);
            ListNode* d1 = new ListNode(val);
            //  Placing a new node after current
            d1->next = curr->next;
            curr->next = d1;
            curr = d1->next;
        }
        return head;
    }
};