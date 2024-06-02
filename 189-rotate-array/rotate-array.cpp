class Solution {
public:
    void rotate(vector<int>& nums, int k) {
  
        int n=nums.size();
              vector<int>vc(n,-1);
        for(int i=0; i<n;i++){
            vc[(i+k)%n]=nums[i];
        }
        nums=vc;
    }
};