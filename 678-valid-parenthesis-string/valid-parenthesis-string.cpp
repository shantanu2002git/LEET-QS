class Solution {
public:
    bool checkValidString(string s) {
        int opn=0,cls=0;
for(auto it : s){
    opn+= (it=='(') ? 1 : -1;
    cls+= (it!=')') ? 1 : -1;

    if(cls<0) break;
    opn=max(opn,0);
}
return opn==0;
    }
};