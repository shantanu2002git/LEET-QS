class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.size(),count=0;
        for(int i=0; i<n; i++){
            bool flg=0;
            for(int j=0; j<n-1; j++){
                if(s[j]=='0' && s[j+1]=='1'){
                    swap(s[j],s[j+1]);
                    j++; flg=1;
                }
            }
            if(flg){
                count++;
            }
        }
        return count;
    }
};
/*
in : 
0 1 1 0 1 0 1

1 1 0 0 1 1 0
1 1 0 1 0 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
*/
