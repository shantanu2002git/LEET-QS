// class Solution {
//     private:
//     long long cal(int idx,int n,vector<vector<int>>& questions,vector<int>&dp){
//         if(idx>=n){
//             return 0;
//         }
//         if(dp[idx]!=-1){
//             return dp[idx];
//         }
//         long long int nttk=cal(idx+1,n,questions,dp);
//         long long int ttk;
       
//            ttk=questions[idx][0]+cal(idx+questions[idx][1]+1,n,questions,dp);
//         return dp[idx]=max(nttk,ttk);
//     }
// public:
// /*
//  long long helper(vector<vector<int>>& q, int i,int n, vector<int>&dp){
//        if(i>=n) return 0;
//        if(dp[i]!=-1) return dp[i];
//        long long t   = q[i][0] + helper(q ,i+1+q[i][1], n,dp);
//        long long n_t = helper(q,i+1,n,dp);
//        return dp[i]= max(t,n_t);
// }
// */

//     long long mostPoints(vector<vector<int>>& questions) {
//         int n=questions.size();
//       vector<int>dp(n+1,-1);
//       return cal(0,n,questions,dp);
//      /* return helper(questions,0,n,dp);*/

//     }
// };


#define ll long long int
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
       /*
        vector<ll> dp(n+1, 0);
        for(int i=n-1; i>=0 ;i--){
            int point = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(n, i+jump+1);
            dp[i] = max(dp[i+1], point + dp[nextQuestion]);
        }
        return dp[0];
        */
     
    long long dp[200001] = {};
    for (int i = q.size() - 1; i >= 0; --i)
        dp[i] = max(q[i][0] + dp[q[i][1] + i + 1], dp[i + 1]);
    return dp[0];
    }
};

