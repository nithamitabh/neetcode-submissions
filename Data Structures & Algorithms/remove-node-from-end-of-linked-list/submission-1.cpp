class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: Move fast n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Step 2: If fast is null, we remove the head node
        if (!fast) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Step 3: Move both until fast->next is null
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 4: Delete slow->next
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
