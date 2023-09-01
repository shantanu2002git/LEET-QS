class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,n=height.size(),j=n-1,mx=-1;
        while(i<=j){
          int hi=min(height[i],height[j]);
          int dis=(j-i);
          int water=hi*dis;
          mx=max(mx,water);
          if(height[i]<height[j]){
            i++;
          }else{
            j--;
          }
        }
        return mx;
    }
};