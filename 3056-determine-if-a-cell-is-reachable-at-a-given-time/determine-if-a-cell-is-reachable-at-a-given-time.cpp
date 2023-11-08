class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       if(sx==fx && sy==fy){
           return (t>1 || t==0);//t>=0 wrong
       }

       int wid=abs(sx-fx);
       int hig=abs(sy-fy);

       int extraT=abs(wid-hig);
       return (min(wid,hig)+extraT)<=t;
       
    }
};