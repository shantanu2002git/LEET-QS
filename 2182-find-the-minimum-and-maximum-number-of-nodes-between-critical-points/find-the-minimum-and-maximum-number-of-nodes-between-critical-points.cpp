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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prv = head, *curr = head->next, *nxt = head->next->next;
        int idx = 1;
        vector<int> arr;
        while (curr->next != NULL) {
            if (prv->val < curr->val && curr->val > nxt->val) {
                arr.push_back(idx);
            } else if (prv->val > curr->val && curr->val < nxt->val) {
                arr.push_back(idx);
            }
            idx++;
            prv = prv->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        int n = arr.size();
        if (n < 2) {
            return {-1, -1};
        }
        int res, min_d = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            min_d = min(min_d, (arr[i] - arr[i - 1]));
        }
        return {min_d, {arr[n - 1] - arr[0]}};
    }
};