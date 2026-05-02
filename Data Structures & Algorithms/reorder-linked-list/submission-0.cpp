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
    void reorderList(ListNode* head) {
        //edge cases atleast three node required
        if(!head || !head->next || !head->next->next) return;
        //1. Find the middle = two pointers slow will my middle node
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2.reverse the second half
        ListNode *prev= nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;
        while(curr){
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        //3. merge it
        ListNode *first = head;
        ListNode *sec = prev;
        while(sec){
            ListNode *tmp1 = first->next;
            ListNode *tmp2  = sec->next;
            first->next = sec;
            sec->next = tmp1;
            first= tmp1;
            sec= tmp2;
        }
    }
};
