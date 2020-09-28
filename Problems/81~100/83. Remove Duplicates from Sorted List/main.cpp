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
        auto first = head;
        auto second = head;
        while(first)
        {
            while(first && first->val == second->val) first = first->next;
            second -> next = first;
            second = second -> next;
        }
        return head;
    }
};
