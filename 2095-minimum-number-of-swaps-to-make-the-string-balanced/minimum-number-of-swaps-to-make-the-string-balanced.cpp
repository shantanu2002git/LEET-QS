class Solution {
public:
    int minSwaps(string s) {
        int cox=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='['){
                cox++;
            }else if(cox!=0){
                cox--;
            }
        }
        return (cox+1)/2;
    }
};