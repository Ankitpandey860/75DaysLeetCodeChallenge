class Solution {
public:
    const int mod=1e9+7;
    int solve(int n, int req, vector<int>& group, vector<int>& profit,int i,vector<vector<vector<int>>>& dp){
        if(i>=group.size()&&req<=0) return 1;
        if(i>=group.size()) return 0;
        if(dp[i][n][req]!=-1) return dp[i][n][req];
        //exc
        int exc=solve(n,req,group,profit,i+1,dp);
        int inc=0;
        //inc
        if(group[i]<=n){
            /*int temp=group[i];
            group[i]-=n;*/
            int lft=req>profit[i]?req-profit[i]:0;
            inc=solve(n-group[i],lft,group,profit,i+1,dp)%mod;
            //group[i]=temp;
        }
        return dp[i][n][req]= (1ll*inc+exc)%mod;
    }
    int profitableSchemes(int n, int req, vector<int>& group, vector<int>& profit) {
        int len=group.size();
        vector<vector<vector<int>>>dp(len,vector<vector<int>>(n+1,vector<int>(req+1,-1)));
        return solve(n,req,group,profit,0,dp);
    }
};