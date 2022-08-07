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
    
    ListNode* reverseList(ListNode* head){
        if(head == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* next = nullptr;
        
        curr = head;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = reverseList(l1);
        ListNode* ptr2 = reverseList(l2);
        
        ListNode* resultHead = nullptr;
        
        
        int carry = 0;
        int sum = 0;
        
        while(ptr1 != nullptr || ptr2 != nullptr){
            
            cout << "In here" << endl;
                    
            sum += carry;
            sum += (ptr1 != nullptr) ? ptr1->val : 0;
            sum += (ptr2 != nullptr) ? ptr2->val : 0;
                        
            
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
        
            
            node->next = resultHead;
            resultHead = node;
            
            sum = 0;
            cout << "Out here" << endl;
            
            ptr1 = ptr1 != nullptr ? ptr1->next : nullptr;
            ptr2 = ptr2 != nullptr ? ptr2->next : nullptr;
        
        }
        
        if(carry != 0){
          ListNode* node = new ListNode(1);
          node->next = resultHead;
          resultHead = node;
        }
        
        return resultHead;
    }
};