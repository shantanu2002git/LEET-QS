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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* run = res;
        int ex = 0;
        while (l1 || l2 || ex) {
            int s=0;
            if (l1) {
                s = s + l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s = s + l2->val;
                l2 = l2->next;
            }

            int ts = s + ex;
            ex = ts / 10;
            ListNode* nd = new ListNode(ts % 10);
            run->next = nd;
            run = run->next;
        }
        return res->next;
    }
};