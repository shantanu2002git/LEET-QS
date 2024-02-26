class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0,c;
        for(int i=0; i<32; i++){
            c=0;
            for(int j=0;j<nums.size(); j++){
                if(((nums[j]>>i)&1)>0){
                   c++;
                }
            }
            c=c%3;
            if(c!=0){
                res =res|1<<i;
            }
        }
        return res;
    }
};