class Solution {
public:
    int arr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    const int mod=1e9+7;
    int solve(int m, int n, int maxMove, int i, int j,vector<vector<vector<int>>>& dp){
        if(i>=m||j>=n||i<0||j<0) return 1;
        if(maxMove==0) return 0;
        if(dp[maxMove][i][j]!=-1) return dp[maxMove][i][j];
        long long ans=0;
        for(auto it:arr){
            int nr=i+it[0];
            int nc=j+it[1];
            ans+=solve(m,n,maxMove-1,nr,nc,dp);
        }
        return dp[maxMove][i][j]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m,vector<int>(n,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};