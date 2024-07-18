class Solution {
public:
    int minimumRecolors(string bl, int k) {
        int n=bl.size(),mx=1e9,tr;
        for(int i=0; i<n; i++){
            int cl=0;
            tr=0;
            for(int j=i; j<n; j++){
                if(bl[j]=='W'){
                    cl++;
                }
               
                tr++;
                 if(tr==k){
                    mx=min(cl,mx);
                }
            }
            cout<<tr<<" ";
        }
        
        return mx;
    }
};