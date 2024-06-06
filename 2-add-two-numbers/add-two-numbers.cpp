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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* nx=new ListNode(-1);
      ListNode* go=nx;
      int ext=0,s=0;
      while(l1 || l2 || ext){
        s=0;
        if(l1){
            s=s+l1->val;
            l1=l1->next;
        }

        if(l2){
            s=s+l2->val;
            l2=l2->next;

        }
        s=s+ext;
        ext=s/10;
        ListNode* nd=new ListNode(s%10);
        go->next=nd;

        go=go->next;
      }
      return nx->next;
    }
};