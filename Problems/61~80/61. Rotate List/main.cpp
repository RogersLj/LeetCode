/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;

        int n =0;
        for(auto p = head;p;p = p->next) n++;
        
        k %= n; 
        auto first = head;
        auto second = head;
        while(k--) first = first->next;
        while(first->next){
            first = first->next;
            second = second->next;
        }

        first->next = head;
        head = second->next;
        second->next = NULL;

        return head;      
    }
};
