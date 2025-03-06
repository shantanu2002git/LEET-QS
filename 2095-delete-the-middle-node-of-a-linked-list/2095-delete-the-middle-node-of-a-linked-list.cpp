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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *middle, *prv=head;
        ListNode *fast = head, *slow = head;

        while(fast && fast->next ) {
            fast = fast->next->next;
            prv = slow;
            slow = slow->next;
        }
        prv->next = slow->next;
        return head;
    }
};