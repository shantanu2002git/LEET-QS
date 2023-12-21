class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int [][] ans=new int[nums.length/3][3];
        for(int i=2; i<nums.length; i=i+3){
            if(nums[i]-nums[i-2]>k || nums[i]-nums[i-1] >k){
                return new int [0][];
            }
            ans[i/3]=new int[]{nums[i-2],nums[i-1],nums[i]};
        }
        return ans;
    }
}
// 1 1 3 3 4 5 7 8 9