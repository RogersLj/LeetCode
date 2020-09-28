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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;

        auto dummy = new ListNode(-1);
        dummy ->next = head;
        auto a = dummy;
        auto b = dummy;

        for(int i = 0;i<m-1;i++) a = a->next;
        for(int i =0;i<n;i++) b = b->next;

        auto c = a->next;
        auto d = b->next;

        for(auto p = c,q=p->next;q!=d;){
            auto x = q->next;
            q->next = p;
            p = q;
            q = x;
        }
        c->next = d;
        a->next = b;

        return dummy->next;
    }
};
