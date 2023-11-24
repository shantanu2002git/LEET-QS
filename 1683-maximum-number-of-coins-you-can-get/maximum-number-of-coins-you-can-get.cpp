class Solution {
public:
    int maxCoins(vector<int>& piles) {
      int res=0,n=piles.size();
      sort(piles.begin(),piles.end());
      for(int i=n/3; i<n;i=i+2){
          cout<<piles[i]<<" ";
        res=res+piles[i];
      } 
      return res; 
    }
};

/*
2 4 1 2 7 8
1 2 2 4 7 8
A=8 I =7 B=4
A=2 I =2 B=1

I=9
B I A
4 7 8
1 2 2 

4+6+8
1 2 3   4 5 6   7 8 9
B I A
7 8 9
4 5 6
1 2 3

*/

