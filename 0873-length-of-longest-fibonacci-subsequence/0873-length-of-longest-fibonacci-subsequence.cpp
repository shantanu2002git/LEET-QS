class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(),res=0;
        unordered_set<int>uset(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int prvfb=arr[i];
                int currfb=arr[j];
                int len=2;

                int nxtfb=prvfb+currfb;
                while(uset.find(nxtfb)!=uset.end()){
                    int tem=nxtfb;
                    nxtfb=nxtfb+currfb;
                    currfb=tem;

                    res=max(res,++len);

                }
            }
        }
        return res;
    }
};