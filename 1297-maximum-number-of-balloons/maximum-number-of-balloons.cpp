class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // int n=text.size();
        string bb="ballon";
        int b=0,a=0,l=0,o=0,n=0;
        for(auto i : text){
            b=b+(i=='b');
            a=a+(i=='a');
            l=l+(i=='l');
            o=o+(i=='o');
            n=n+(i=='n');
        }
        return min({b,a,l/2,o/2,n});
    }
};