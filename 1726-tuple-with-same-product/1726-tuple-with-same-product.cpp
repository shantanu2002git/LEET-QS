class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>loop1;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                   int mul1=nums[i]*nums[j];
                   loop1[mul1]++;
            }
        }
        int c=0;
        for(auto it : loop1){
            if(it.second==2){
                c++;
            }
        }
        return c*8;
    }
};