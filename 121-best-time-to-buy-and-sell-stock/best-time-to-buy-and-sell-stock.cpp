class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size(),mi=1e9,mx=0;
        for(int i=0; i<n ;i++){
            mi=min(mi,arr[i]);
            mx=max(mx,arr[i]-mi);
        }
        return mx;
    }
};