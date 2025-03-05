class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fst = head, *slw = head;

       
        while (fst && fst->next) {
            fst = fst->next->next;
            slw = slw->next;
            if (slw == fst) { // Cycle detected
                break;
            }
        }

        // If no cycle is detected, return NULL
        if (!fst || !fst->next) return NULL;

        // Step 2: Find the cycle start node
      ListNode*  start = head;  // Move slow to head
        while (slw != start) {
            slw = slw->next;
            start = start->next;
        }

        return start;  
    }
};
