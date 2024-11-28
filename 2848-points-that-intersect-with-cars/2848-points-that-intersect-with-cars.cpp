class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int>st;
        for(auto it : nums)
        {
            int l=it[0], r=it[1];
            for(int i=l; i<=r; i++){
                st.insert(i);
            }
        }
        return st.size();
    }
};