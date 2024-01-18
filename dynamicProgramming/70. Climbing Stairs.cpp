//using memoization
class Solution {
public:
    //Normal recusion
    int recursion(int n){
        if(n==1)return 1;
        if(n==2)return 2;
        return solve(n-1) + solve(n-2);
    }
    //memoization
    int solve(int n,int dp[]){
        if(n==1)return 1;
        if(n==2)return 2;
        if(dp[n]!= -1){
            return dp[n];
        }
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        int dp[55];
        memset(dp,-1,sizeof(dp));
        return solve(n,dp);
    }
};
