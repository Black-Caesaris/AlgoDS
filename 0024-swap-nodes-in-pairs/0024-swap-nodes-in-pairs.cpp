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
//Iterative solution (faster than recursion)
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* ptr1 = dummyHead;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev->next = next;
            ptr1->next = curr;
            ptr1 = prev;
            prev = prev->next;
            if(!prev)
                break;
            curr = prev->next;
        }
        
        return dummyHead->next;
    }
    
    // A much simpler solution using recursion (top voted answer)
//     ListNode* swapPairs(ListNode* head) {
//         if(!head || !head->next)
//             return head;
        
//         ListNode* temp = head->next;
        
//         head->next = swapPairs(head->next->next);
//         temp->next = head;
//         return temp;
//     }
};