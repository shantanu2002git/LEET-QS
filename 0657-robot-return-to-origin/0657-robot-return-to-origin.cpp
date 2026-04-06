class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0, lf=0;
        for(auto i : moves){

            if(i=='U'){
                up++;
            }else if(i=='D'){
                up--;
            }

            if(i=='R'){
                lf++;
            }else if(i=='L'){
                lf--;
            }
        }
        cout<<up<<" "<<lf;
                return (up==0 && lf==0);
    }
};