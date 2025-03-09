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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; // Edge case: If k=1, no need to reverse

        ListNode dummy(0); // Dummy node to handle head changes
        dummy.next = head;
        ListNode *prevGroupEnd = &dummy;

        while (true) {
            // Find the kth node
            ListNode* kthNode = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                kthNode = kthNode->next;
                if (!kthNode) return dummy.next; // If less than k nodes remain, return result
            }

            // Reverse k nodes
            ListNode* prev = kthNode->next;
            ListNode* curr = prevGroupEnd->next;
            ListNode* nextNode;
            
            for (int i = 0; i < k; i++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect with previous part
            ListNode* temp = prevGroupEnd->next;
            prevGroupEnd->next = kthNode;
            prevGroupEnd = temp;
        }
    }
};
