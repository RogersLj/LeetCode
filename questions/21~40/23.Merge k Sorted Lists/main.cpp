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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> heap;

        for (auto list : lists)
           if(list) heap.push({-list -> val, list});

        ListNode* dummy = new ListNode(-1);
        auto cur = dummy;

        while (heap.size())
        {
            auto t = heap.top();
            heap.pop();
            cur = cur -> next = t.second;
            auto p = t.second -> next;
            if (p) heap.push({-p -> val, p}); 
        }

        cur -> next = NULL;
        return dummy -> next;
    }
};
