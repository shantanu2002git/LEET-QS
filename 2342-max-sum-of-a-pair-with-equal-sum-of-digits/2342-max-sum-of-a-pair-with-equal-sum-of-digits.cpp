class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        map<int, int> mps;
        sort(nums.begin(),nums.end());
        for (auto it : nums) {
            string si = to_string(it);
            int ds = 0;
            for (auto i : si) {
                ds = ds + (i - '0');
            }
            if(mps.find(ds)!=mps.end()){
                res=max(res,(mps[ds]+it) );
            }
            mps[ds]=it;
        }
        return res==0 ? -1 : res;
    }
};