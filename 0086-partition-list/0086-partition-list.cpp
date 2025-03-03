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
    ListNode* partition(ListNode* head, int x) {
        ListNode *part1, tem1 = head, tem2 = head, part2;
        ListNode *gop1, gop2;

        part1 = gop1;
        part2 = gop2;

        while (tem1) {
            if (tem1->val < x) {
                gop1 = tem1;
                gop1 = gop1->next;
            }
            tem1 = tem1->next;
        }

        while (tem2) {
            if (tem2->val >= x) {
                gop2 = tem2;
                gop2 = gop2->next;
            }
            tem2 = tem2->next;
        }
        part1->next = part2;

        return part1;
    }
};