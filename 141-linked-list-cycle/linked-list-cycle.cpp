/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return 0;
        }
        ListNode *fst=head,*slw=head;
        while(fst!=NULL&& fst->next!=NULL){
            
            slw=slw->next;
            fst=fst->next->next;
            if(fst==slw){
                return 1;
            }
        }
        return 0;
    }
};