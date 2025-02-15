class Solution {
public:
    bool isUgly(int n) {
        if(n==0){
            return 0;
        }
        for (auto it : {2, 3, 5}) {
            while (n % it == 0) {
                n = n / it;
            }
            //only consider : 2,3,5 So going on untill the number is not able to divide it
        }
        return n == 1;
    }
};