class Solution {
public:
    int majorityElement(vector<int>& nums) {
          int number=0;
        int s = nums.size();
        for(int i=0;i<32;i++){
            int cnt=0;

            for(int j=0;j<s;j++){
                if(nums[j]>>i&1)cnt++;
            }
            if(cnt>(s/2))
                number = number | 1<<i;
        }
        return number;
    }
};