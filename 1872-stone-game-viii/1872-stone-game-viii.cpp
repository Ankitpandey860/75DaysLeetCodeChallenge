class Solution {
public:
    int solve(vector<int>& stones,int i,vector<int>& prefix,vector<int>& dp){
        if(i == prefix.size() - 1)
            return prefix[i];

        if(i >= prefix.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        int itnahi=prefix[i]-solve(stones,i+1,prefix,dp);
        int orjodo=solve(stones,i+1,prefix,dp);
        ans=max(itnahi,orjodo);
        return dp[i]=ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        vector<int>dp(n,-1);
        return solve(stones,1,prefix,dp);
    }
};