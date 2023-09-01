class Solution {
public:
    int maxArea(vector<int>& height) {
      int n=height.size();
    int i=0,j=n-1;
    int mx=-1e9;
    while(i<=j){
      int h=min(height[i],height[j]);
      int wt=(j-i)*h;
      mx=max(mx,wt);
      if(height[i]<height[j]){
        i++;
      }else{
        j--;
      }
    }
    return mx;
}
};