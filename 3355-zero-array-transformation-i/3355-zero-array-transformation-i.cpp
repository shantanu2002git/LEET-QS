class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> diff(n, 0);
/*
question like this index_i, index_j, XOR k
to implement this :

arr[index_i]^=k
arr[index_j+1]^=k

because XOR of XOR clancle out for "K"

*/
        for (auto  it : q) {
            diff[it[0]] += -1;
            if (it[1] < n - 1) {
                diff[it[1] + 1] += 1;
            }
        }
        for (int i = 1; i < n; i++) {
            diff[i] = diff[i - 1] + diff[i];
        }
        for (auto it : diff) {
            cout << it << " ";
        }
        for (int i = 0; i < n; i++) {
            if ((nums[i] + diff[i]) > 0) {
                return 0;
            }
        }
        return 1;
    }
};