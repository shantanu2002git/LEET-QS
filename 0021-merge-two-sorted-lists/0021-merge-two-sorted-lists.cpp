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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* nwhead = new ListNode(-1);
        ListNode* go = nwhead;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                go->next = list1;
                list1 = list1->next;
            } else {
                go->next = list2;
                list2 = list2->next;
            }
            go = go->next;
        }

        while (list1) {
            go->next = list1;
            go = go->next;
            list1 = list1->next;
        }

        while (list2) {
            go->next = list2;
            go = go->next;
            list2 = list2->next;
        }

        return nwhead->next;
    }
};