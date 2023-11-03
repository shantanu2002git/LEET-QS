class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>res;
        int j=0,on=1,tn=target.size();
        while(j<target.size()){
            if(target[j]==on){
                res.push_back("Push");
                j++;
            }else{
                res.push_back("Push");
                res.push_back("Pop");
            }
            on++;
        }
        return res;
    }
};