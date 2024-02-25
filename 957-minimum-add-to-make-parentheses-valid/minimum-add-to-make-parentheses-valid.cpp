class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,count=0;
        for(auto i : s){
            if(i=='('){
                open++;
            }else{
                if(open!=0){
                    open--;
                    continue;
                }else if(open==0){
                    count++;
                }
            }
        }
        return count+open;
    }
};