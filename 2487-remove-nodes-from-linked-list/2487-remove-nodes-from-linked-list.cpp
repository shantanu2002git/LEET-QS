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
        if (!head) return NULL;

        // Step 1: Reverse the linked list
        ListNode* revHead = reverse(head);

        // Step 2: Create a new linked list based on the given condition
        ListNode* dummy = new ListNode(-1); // Dummy node
        ListNode* go = dummy;
        ListNode* curr = revHead;

        int maxVal = curr->val; // Track maximum value encountered
        while (curr) {
            if (curr->val >= maxVal) { // Only keep nodes meeting the condition
                maxVal = curr->val;
                go->next = new ListNode(curr->val);
                go = go->next;
            }
            curr = curr->next;
        }
        ListNode* finalList = reverse(dummy->next);

        // Free memory of dummy node
        delete dummy;

        return finalList;
    }
};
