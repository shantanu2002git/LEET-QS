class Solution {
public:
    int numberOfChild(int n, int k) {
        // Calculate the position of the child who receives the ball after k seconds
        int pos = k % (2 * (n - 1)); // the ball returns to the same position after 2*(n-1) passes
        if(n>k){
            return k;
        }
        
        if (pos < n) {
            return pos;
        } else {
            return 2 * (n - 1) - pos;
        }
    }
};
