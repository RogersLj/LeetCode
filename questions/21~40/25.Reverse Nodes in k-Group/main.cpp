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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy -> next = head;
        auto p = dummy;

        while(p)
        {
            int s = 0;
            for(auto i = p -> next; i && s < k; i = i -> next) s++;
            if(s < k) break;

            s = 1;
            auto a = p->next;
            auto b = a, c = a->next;
            while(s<k)
            {
                auto d = c->next;
                c->next = b;
                b = c;
                c = d;
                s++;
            } 
            p->next = b;
            a->next = c;
            p = a;
        }
        return dummy -> next;
    }
};
