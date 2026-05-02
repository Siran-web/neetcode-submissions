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
    int len(ListNode* head){
        int size = 0;

        while(head){
            head = head->next;
            size++;
        }
        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = len(head);
        n = size - n;

        if(n == 0){
            return head -> next;
        }

        ListNode* temp = head;
        while(n > 1){
            temp = temp->next;
            n--;
        }

        ListNode* next_next = temp->next->next;
        delete(temp->next);
        temp->next = next_next;
        
        return head;
    }
};
