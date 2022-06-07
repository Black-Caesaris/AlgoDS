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
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        
        ListNode* old_head = head;
        ListNode* tail;
        int n = 0;
        
        while(head !=  nullptr){
            tail = head;
            head = head->next;
            n++;
        }
        
        tail->next = old_head;
        
        k = k % n ;
        int x = n-k;
        ListNode* temp = old_head;
        while(x > 0){
            tail = temp;
            temp = temp->next;
            x--;
        }
        
        tail->next = nullptr;
        
        return temp;

    }
};