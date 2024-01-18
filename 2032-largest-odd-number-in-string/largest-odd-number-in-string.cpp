class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size(),i;
        for( i=n-1; i>=0; i--){
            if((num[i]-'0')%2!=0){
                break;
            }
        }
        cout<<i<<endl;
        return num.substr(0,i+1);
    }
};