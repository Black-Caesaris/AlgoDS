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
    
    ListNode* findMid(ListNode* head) {
        if(head == nullptr)
            return head;
        
        ListNode* slow = nullptr;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            if(!slow){
                slow = head;
            } else {
                slow = slow->next;
            }
            fast = fast->next->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }
    
    ListNode* mergeList(ListNode* head1, ListNode* head2){
        if(head1 == nullptr) {
             return head2;
        }

        if(head2 == nullptr) {
            return head1;
        }
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* prev;
        prev = dummyHead;
        
        while(head1 != nullptr || head2 != nullptr) {
            int a = head1 == nullptr ? INT_MAX : head1->val;
            int b = head2 == nullptr ? INT_MAX : head2->val;
            
            if(a<b) {
                prev->next = head1;
                prev = head1;
                head1 = head1->next;
            } else {
                prev->next = head2;
                prev = head2;
                head2 = head2->next;
            }
        }

            
          return dummyHead->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr) 
            return head;
        
        if(head->next == nullptr)
            return head;
        
        ListNode* mid = findMid(head);
        cout << mid->val ;

        ListNode* left = sortList(head);

        ListNode* right = sortList(mid);

        ListNode* mergedList = mergeList(left, right);
        
        return mergedList;
        
    }
};