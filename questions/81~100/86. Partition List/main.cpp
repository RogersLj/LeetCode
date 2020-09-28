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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(-1), right(-1);
        ListNode *p = &left, *q = &right;
        auto cur = head;
        while (cur)
        {
            if (cur -> val < x) p = p -> next = cur;
            else q = q -> next = cur;
            cur = cur -> next;
        }

        q -> next = NULL;
        p -> next = right.next;

        return left.next;
    }
};
