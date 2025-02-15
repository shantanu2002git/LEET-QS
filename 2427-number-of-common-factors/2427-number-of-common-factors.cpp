class Solution {
public:
    int commonFactors(int a, int b) {
        int lp=__gcd(a,b);
        int res=0;
        for(int i=1; i<=lp; i++){
            if(a%i==0 && b%i==0){
                res++;
            }
        }
        return res;
    }
};