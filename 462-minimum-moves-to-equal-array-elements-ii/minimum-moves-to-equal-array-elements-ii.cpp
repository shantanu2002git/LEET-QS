class Solution {
public:
    int minMoves2(vector<int>& nums) {
       int n=nums.size(),s=0;
       sort(nums.begin(),nums.end());
       int md=nums[n/2];
for(auto it : nums){
    s=s+abs(md-it);
}
return s;
    }
};

/*
1 2 9 10
8 7 0 1

*/