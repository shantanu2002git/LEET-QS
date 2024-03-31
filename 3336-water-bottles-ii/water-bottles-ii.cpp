class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        /*
        int res = numBottles, emp = res;
        while (emp >= numExchange) {
            res = res + 1;
            emp = emp - numExchange;
            emp += 1;
            numExchange += 1;
        }
        return res;
        */
        int nb = numBottles, ex = numExchange;
        int res = 0;
        while (nb > 0) {
            if (nb >= ex) {
                nb = nb - ex;
                res = res + ex;
                nb = nb + 1;
                ex = ex + 1;
            } else {
                break;
            }
        }
     
        return res + nb;
    }
};