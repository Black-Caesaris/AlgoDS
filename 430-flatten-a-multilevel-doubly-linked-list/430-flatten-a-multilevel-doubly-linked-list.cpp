/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* recursiveFlatten(Node* prev, Node* curr){
        if(curr == nullptr){
            return prev;
        }
        
        prev->next = curr;
        curr->prev = prev;
        
        Node* tempNext = curr->next;
        
        Node* tail = recursiveFlatten(curr, curr->child);
        curr->child = nullptr;
        
        return recursiveFlatten(tail, tempNext);
        
    }
    
    
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        Node* dummyHead = new Node();
        dummyHead->next = head;
        head->prev = dummyHead;
        recursiveFlatten(dummyHead, head);
        dummyHead->next->prev = nullptr;
        return dummyHead->next;
        
    }
    

};