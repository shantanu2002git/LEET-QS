/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

 protected:
    
int callen(ListNode* he){
    int c=0;
    while(he){
        c++;
        he=he->next;
    }
    return c;
}
public:
    ListNode *getIntersectionNode(ListNode *he1, ListNode *he2) {
        ListNode* si1, *si2, *si,*sto;
     int n1= callen(he1), n2=callen(he2);
     int k=abs(n1-n2);

     while(k--){
         if(n1>n2){
             he1=he1->next;
         }else{
             he2=he2->next;
         }
     }
     while(he1!=he2){
         he1=he1->next;
         he2=he2->next;
     }
     return he1;
    }
};