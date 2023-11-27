class Solution {
public:
vector<vector<int>>memo;
int n,mod=1e9+7;
vector<vector<int>>jump={
    {4,6},//0
    {6,8},//1
    {7,9},//2
    {4,8},//3
    {3,9,0},//4
    {},//5
    {1,7,0},//6
    {2,6},//7
    {1,3},//8
    {2,4}
};


int call(int n, int sq){
    if(n==0){
        return 1;
    }

    if(memo[n][sq]!=-1){
        return memo[n][sq];
    }

    int ans=0;
    for(int nxt : jump[sq]){
        ans=(ans+call(n-1,nxt))%mod;
    }
    return memo[n][sq]=ans;
}
    int knightDialer(int n) {
        this->n=n;
        memo=vector(n+1,vector(10,-1));
        int res=0;
        for(int sq=0; sq<=9; sq++){
            res=(res+call(n-1,sq))%mod;
        }
        return res;
    }
};

/*
rw 0 : c1-> 18, 16 | c2-> 27,29 | c3->38
rw 1 : c1-> 43, 49, 40 | c2->    | c3-> 06,67
rw 3 : 72,76 | 83,81 | 92,94
rw 4 : 04,06

*/