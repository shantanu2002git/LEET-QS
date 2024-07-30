class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int n = num.size();
        int carry = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            int sum = num[i] + k % 10 + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
            k /= 10;
        }
        
       
        while (k > 0) {
            int sum = k % 10 + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
            k /= 10;
        }
        
       
        if (carry > 0) {
            res.push_back(carry);
        }
        
      
        reverse(res.begin(), res.end());
        
        return res;
    }
};
