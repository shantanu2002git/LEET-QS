class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        priority_queue<int, vector<int>, greater<int>> pastending; // previously ending it can cover
        priority_queue<int> mxp; // it will cover max distance

        sort(q.begin(), q.end()); // sort  the query so that we can track of nums array from 0-n index
        int n = nums.size(), qi = 0;
        int usinq = 0;
        // vector<int> pastending;
        for (int i = 0; i < n; i++) {
            while (qi < q.size() && q[qi][0] == i) {
                mxp.push(q[qi][1]);
                qi++;
            }

            nums[i] = nums[i] - pastending.size();
            while (nums[i] > 0 && !mxp.empty() && i <= mxp.top()) {
                int end = mxp.top();
                mxp.pop();
                pastending.push(end);
                usinq++;
                nums[i]--;
            }

            if(nums[i]>0) return -1;
            while(!pastending.empty() && pastending.top()<=i){
                pastending.pop();
            }
        }
        return q.size()-usinq;
    }
};