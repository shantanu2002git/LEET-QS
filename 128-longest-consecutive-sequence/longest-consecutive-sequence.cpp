class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int prv = 1e9, rs = 0, mxi=0;
        for (auto it : mp) {
            cout<<prv<<" "<<it.first<<endl;
            if(prv==it.first) continue;
            if (prv + 1 == it.first ) {
                rs++;
            }else{
                rs=1;
            }
            prv = it.first;
            mxi=max(mxi,rs);
        }
        return mxi;
    }
};