class Solution {
public:
    bool squareIsWhite(string c) {
        /*
        int rw=c[0]-'a',cl=c[1]-'0';
        if(((rw+1)%2!=0 && cl%2!=0) || ((rw+1)%2==0 && cl%2==0)){
            return 0;
        }
        cout<<rw+1<<cl;
        return 1;
        */
        return (c[0] + c[1]) % 2;
    }
};