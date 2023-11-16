class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        for (int i = 0; i < nums.size(); ++i) {
            char currentChar = nums[i][i];
            char oppositeChar = (currentChar == '0') ? '1' : '0';

            // add the opposite character to the result string
            ans += oppositeChar;
        }

        return ans;
    }
};

/*
it will help help when this condition will follow  : 
strings nums containing n unique binary strings each of length n
*/