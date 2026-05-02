

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> arr1, arr2;

        // Step 1: Store all digits from l1 and l2 into vectors
        while (l1 != nullptr) {
            arr1.push_back(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            arr2.push_back(l2->val);
            l2 = l2->next;
        }

        // Step 2: Add corresponding digits with carry
        int i = 0, carry = 0;
        vector<int> result;
        int n1 = arr1.size();
        int n2 = arr2.size();

        while (i < n1 || i < n2 || carry > 0) {
            int sum = carry;
            if (i < n1) sum += arr1[i];
            if (i < n2) sum += arr2[i];
            result.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        // Step 3: Build the result linked list from result vector
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int digit : result) {
            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        return dummy->next;
    }
};
