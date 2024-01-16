class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ex) {
        vector<bool>res;
        int mx=*max_element(candies.begin(),candies.end()),n=candies.size();


for(int i=0; i<n; i++){
if(candies[i]+ex>=mx){
    res.push_back(true);
    mx=max(mx,candies[i]);
}else{
     res.push_back(false);
}
}
return res;
    }
};

/*
2 3 5 1 3
5 6 8 4 6
*/