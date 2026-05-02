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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode *curr= head;
        int cnt= 0;
        while(curr && cnt<k){
            curr = curr->next;
            cnt++;
        }
        if(cnt<k) return head;
        //Reverse first k nodes
        ListNode *prev = nullptr;
        curr = head;
        for(int i = 0;i<k;++i){
            ListNode *node = curr->next;
            curr->next = prev;
            prev= curr;
            curr = node;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};
