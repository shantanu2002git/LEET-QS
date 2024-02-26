#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        // Iterate over each number in the array
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1; // Get the index corresponding to the number
            
            // If the number is positive, make the number at its index negative
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
        }
        
        // Iterate over the modified array to find indices with positive numbers
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) // If the number at index i is positive
                res.push_back(i + 1); // Add i+1 to the result (1-indexed)
        }
        
        return res;
    }
};
