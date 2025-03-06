class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }
        ListNode* temp = second->next;
        second->next = temp->next;
        delete temp;

        return dummy.next;
    }
};

