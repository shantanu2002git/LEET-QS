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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty() ){
            return NULL;
        }
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode nwlist(-1);
        ListNode* run = &nwlist;
        for (auto it : lists) {
            if(it==NULL) continue;
            pq.push(it);
        }
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            run->next = tp;
            run = run->next;
            if (tp->next) {
                pq.push(tp->next);
            }
        }

        return nwlist.next;
    }
};