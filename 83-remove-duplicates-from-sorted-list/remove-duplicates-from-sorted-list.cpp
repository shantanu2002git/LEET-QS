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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tem = head;
        while (tem) {
            while (tem->next && tem->val == tem->next->val) {
                tem->next = tem->next->next;
            }

            tem = tem->next;
        }
        return head;
    }
};