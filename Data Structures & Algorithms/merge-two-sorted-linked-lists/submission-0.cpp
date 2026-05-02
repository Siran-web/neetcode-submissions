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
    void insertAtHead(ListNode* &l , ListNode* &list1){
        ListNode* newNode = new ListNode(list1->val);
        l->next = newNode;
        l = l->next;
        list1 = list1->next;
    }
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* l = new ListNode(-1);
        ListNode* copy = l;
        
        while(list1 && list2){
            if(list1 -> val <= list2 -> val)
                insertAtHead(l , list1);
            else 
                insertAtHead(l , list2);
            
        }
        
        while(list1)
            insertAtHead(l , list1);
        
        while(list2)
            insertAtHead(l , list2);
        
        return copy->next;
    }
};
