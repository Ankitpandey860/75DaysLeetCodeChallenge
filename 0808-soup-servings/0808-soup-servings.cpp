class Solution {
public:
    double solve(int a,int b,vector<vector<double>>& dp){
        if(a<=0&&b<=0) return 0.500000;
        if(a<=0) return 1.000000;
        if(b<=0) return 0.000000;
        if(dp[a][b]!=-1) return dp[a][b];
        double first=solve(a-100,b,dp);
        double second=solve(a-75,b-25,dp);
        double third=solve(a-50,b-50,dp);
        double fourth=solve(a-25,b-75,dp);
        return dp[a][b]=(first+second+third+fourth)*0.250000;
    }
    double soupServings(int n) {
        if(n>=4400) return 1;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return solve(n,n,dp);
    }
};