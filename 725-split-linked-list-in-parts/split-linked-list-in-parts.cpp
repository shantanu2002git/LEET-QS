class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int len = 0;
        ListNode* tem = root;
        
        while (tem) {
            len++;
            tem = tem->next;
        }
        
        int nmNode = len / k;
        int ext = len % k;
        tem = root;
        
        for (int i = 0; i < k; i++) {
            res.push_back(tem);
            int strt_len = 1;
            
            while (strt_len < nmNode && tem) {
                tem = tem->next;
                strt_len++;
            }
            
            if (ext > 0 && len>k) {
                tem = tem->next;
                ext--;
            }
            
            if (tem) {
                ListNode* x = tem->next;
                tem->next = NULL;
                tem = x;
            }
        }
        
        return res;
    }
};
