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
        //Wether the LL exists or not 
        if(!head)
            return head;
        ListNode *tail = head;
        int listlength = 1;
        
        //Finding the tail and length of linklist
        while(tail->next){
            listlength++;
            tail = tail -> next;
        }
        
        tail -> next = head;
        
        int newhead = listlength - k % listlength; // As constraint of k is 2 * 10^9 
        
        for( int i=0; i< newhead; i++){
            tail = tail ->next;
        }
        
        head = tail -> next;
        tail -> next = NULL;
        return head;
        
        
    }
};