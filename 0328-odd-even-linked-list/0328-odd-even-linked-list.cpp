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
    ListNode* oddEvenList(ListNode* head) {
          if (!head || !head->next) return head; // ✅ Edge case: empty or single node

        ListNode *oddindex = new ListNode(-1), *evenindex = new ListNode(-1);
        ListNode *godd = oddindex, *goev = evenindex;
        int index = 1;
        while (head) {
            if (index % 2 == 1) {
                godd->next = head;
                godd = godd->next;
            } else {
                goev->next = head;
                goev = goev->next;
            }
            index++;
            head=head->next;
        }
             
        godd->next = evenindex->next;
        
        // ✅******* Ensure the last even node points to NULL
        goev->next = nullptr;

        return oddindex->next;
    }
};