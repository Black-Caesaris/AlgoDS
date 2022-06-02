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
    
    ListNode* newhead(ListNode* head){
        if(head == nullptr) return nullptr;
        
        if(head->next == nullptr) return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        ListNode* n = curr->next;
        
        curr->next = prev;
        prev->next = newhead(n);
        
        return curr;
        
        
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        
        return newhead(head);
    }
};