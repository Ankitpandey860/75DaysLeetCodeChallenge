class Solution {
public:
    int mod=1e9+7;
    int solve(int n,vector<int>& dp){
        
        if(n<=1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        long long ans=solve(n-1,dp)+solve(n-2,dp);
        for(int i=0;i<=n-3;i++){
            ans=(ans%mod+(2ll*solve(i,dp))%mod)%mod;
        }
        return dp[n]=ans%mod;
    }
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};