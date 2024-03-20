class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int fs = 0;
        ListNode* l1 = list1, *tc1 = nullptr, *tc2 = nullptr;
        
        while (l1 != nullptr) {
            if (fs == a - 1) {
                tc1 = l1;
            }
            if (fs == b-1) {
                tc2 = l1->next;
                break; 
            }
            l1 = l1->next;
            fs++;
        }
        
        tc1->next = list2;
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = tc2->next;
        
        return list1;
    }
};
