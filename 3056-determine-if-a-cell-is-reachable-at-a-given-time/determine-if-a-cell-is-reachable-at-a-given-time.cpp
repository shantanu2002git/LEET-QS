class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       if(sx==fx && sy==fy){
           return (t>1 || t==0);//t>=0 wrong
       }

       int wid=abs(sx-fx);
       int hig=abs(sy-fy);

       int extraT=abs(wid-hig);//Calculate the number of diagonal moves needed corner_moves as the absolute difference between height and width.
       return (min(wid,hig)+extraT)<=t;
       
    }
};