class Solution {
public:
int dig(int num){
   int d=0;
   while(num>0){
       int r=num%10;
       d=d+(r*r);
       num=num/10;
   } 
   return d;
}
    bool isHappy(int n) {
        int sum=n;
        while(sum!=1){
            sum=dig(sum);
            if(sum==1) return true;
            else if(sum==4) return false;
        }
        return true;
    }
};