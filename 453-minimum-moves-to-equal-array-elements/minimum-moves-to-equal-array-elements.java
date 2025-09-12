class Solution {
    public int minMoves(int[] nums) {
        int mi=Integer.MAX_VALUE;
        int n=nums.length;
        for(int i=0; i<n; i++){
            mi=Math.min(mi,nums[i]);
        }
        int res=0;
        for(int i=0; i<n; i++){
            res=res+(nums[i]-mi);
        }
        return res;
    }
}