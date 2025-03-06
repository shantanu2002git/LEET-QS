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
    int countnode(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* cnd = head;
        int n = countnode(cnd);
         if (k == n) return head->next;
        int stk = n - k- 1;
        auto it = head;
        while (stk > 0) {
            it = it->next;
            stk--;
        }
        it->next = it->next->next;

        return head;
    }
};