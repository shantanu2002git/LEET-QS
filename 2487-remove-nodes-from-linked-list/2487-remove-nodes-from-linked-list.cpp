class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *nextNode;
        while (head) {
            nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head)
            return NULL;

        // Step 1: Reverse the linked list
        ListNode* revHead = reverse(head);

        ListNode* nwlist = new ListNode(-1);
        ListNode* going = nwlist;

        int maxval = revHead->val;
        while (revHead) {
            if (revHead->val >= maxval) {
                going->next = new ListNode(revHead->val) ;
                maxval = revHead->val;
                going = going->next;
            }
            revHead = revHead->next;
        }

        return reverse(nwlist->next);
    }
};
