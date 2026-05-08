class Solution {
public:

    int solve(int amount, vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount<0||i>=coins.size()) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int ans=0;
        int take=solve(amount-coins[i],coins,i,dp);
        int skip=solve(amount,coins,i+1,dp);   
        ans+=take+skip;
        return dp[i][amount]=ans;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};