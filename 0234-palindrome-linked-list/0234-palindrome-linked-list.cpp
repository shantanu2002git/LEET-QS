class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* rev = NULL, *store;
        while (head) {
            store = head->next;
            head->next = rev;
            rev = head;
            head = store;
        }
        return rev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; 

        // Step 1: Find the middle node (slow-fast pointer method)
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* revHead = reverse(slow);
        
        ListNode* revPtr = revHead;
        ListNode* headPtr = head;

        // Step 3: Compare the first and second half
        while (revPtr) {  // Only check half the list
            if (headPtr->val != revPtr->val) {
                return false;
            }
            headPtr = headPtr->next;
            revPtr = revPtr->next;
        }

        return true;
    }
};
