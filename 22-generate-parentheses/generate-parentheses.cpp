class Solution {
public:
void cal(int n, int opn, int cls , string st , vector<string>&res){
    if(opn==n && cls==n)
    {
        res.push_back(st);
        return;
    }
    if(opn<n){
        cal(n,opn+1,cls,st+"(",res);
    }
    if(cls<opn){
        cal(n,opn,cls+1,st+")",res);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        cal(n,0,0,"",res);
        return res;
    }
};