class Solution {
public:
    int topBottomRecursive(vector<int>& cost,int i){
        if(i<0) return 0;
        if(i==1 || i==0) return cost[i];
        return cost[i]+ min(topBottomRecursive(cost,i-2),topBottomRecursive(cost,i-1));
    }
    int topBottomDP(vector<int>& cost,int i,int dp[]){
        if(i<0) return 0;
        if(i==1 || i==0) return cost[i];
        if(dp[i]!= -1) return dp[i];
        return dp[i] = cost[i]+ min(topBottomDP(cost,i-2,dp),topBottomDP(cost,i-1,dp));
    }
    int bottomUp(vector<int>& cost){
        int dp[1010];
        memset(dp,-1,sizeof(dp));
        int n= cost.size();
        dp[n+1] =0;
        dp[n] = 0; 
        int i;
        for(i=n-1;i>-1;i--){
            dp[i]= cost[i]+ min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
    int simpleSolution(vector<int>&cost){
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //SOLVED USING TOP BOTTOM DP
        int n = cost.size();
        int dp[1010];
        memset(dp,-1,sizeof(dp));
        return min(topBottomDP(cost,n-1,dp),topBottomDP(cost,n-2,dp));
    }
};
