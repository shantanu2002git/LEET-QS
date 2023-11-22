class Solution {
public:
    int reductionOperations(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend()); 
    //Desending order QS : laegest reduse to next smallest element:
    int count = 0, sum = 0, prev = -1;
    
    for (int x : nums) {
        if (x != prev){

            count += sum;
        }
        sum++;
        prev = x;
    }
    
    return count;
}
};