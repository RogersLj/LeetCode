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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL; 
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
                                 
        auto now = dummy;
        auto first = now -> next;
        auto second = now -> next;
        while(first)
        {
            if(second->val != first->val) 
            {
                if(second -> next == first)
                {
                    now = now -> next;
                    second = first;
                }
                second = first;
                now -> next = first; 
            }
            first = first->next;
            if(!first && second->next !=first) now->next = first;
        }

        return dummy -> next;
    }
};
