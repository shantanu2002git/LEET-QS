class Solution {
public:
    int res = 0;
    void call(int idx, vector<int>& num, int n) {
        if (idx >= n) {
            // cout<<"in..";
            // bool valid = true;
            // for (int i = 1; i <= n; i++) {
            //     if ((num[i - 1] % (i)) != 0 && ((i) % num[i - 1]) != 0) {
            //         valid = false;
            //         break;
            //     }
            // }
            // if (valid) {
            //     res++;
            // }

            res++;
            return;
        }

        for (int l = idx; l < n; l++) {
            swap(num[idx], num[l]);
            /*
            
            we can keep checking the elements while being added to the permutation array at every step for the divisibility condition and can stop creating it any further as soon as we find out the element just added to the permutation violates the divisiblity condition.
            
            */
            if ((num[idx] % (idx + 1)) == 0 || ((idx+1) % num[idx]) == 0) {
                call(idx + 1, num, n);
            }
            swap(num[idx], num[l]);
        }
    }
    int countArrangement(int n) {
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }
        call(0, num, n);
        return res;
    }
};