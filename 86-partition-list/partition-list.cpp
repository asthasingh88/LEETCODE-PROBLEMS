
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* d1 = new ListNode(0);
        ListNode* d2 = new ListNode(0);

        ListNode* dummy1 = d1;
        ListNode* dummy2 = d2;

        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->val < x) {
                dummy1->next = curr;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = curr;
                dummy2 = dummy2->next;
            }

            curr = curr->next;
        }

        dummy2->next = NULL;
        dummy1->next = d2->next;

        return d1->next;
    }
};
