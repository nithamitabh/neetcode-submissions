/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // Create copied node interleaved with og one
        Node *curr = head;
        while(curr){
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        // Assign rand pointer
        curr = head;
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        // Seprate og and copied lists
        Node *dummy = new Node(0);
        Node *copyCurr = dummy;
        curr = head;
        while(curr){
            Node *copy = curr->next;
            copyCurr->next = copy;
            copyCurr = copy;
            curr->next = copy->next;
            curr = curr->next; 
        }
        return dummy->next;
    }
};
