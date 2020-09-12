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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(- 1);
        dummy -> next = head;

        auto p = dummy;
        while (p -> next && p -> next -> next)
        {
            auto a = p -> next, b = a -> next;
            a -> next = b -> next;
            p -> next = b;
            b -> next = a;
            p = p -> next -> next;
        }

        return dummy -> next;
    }
};
