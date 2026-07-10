class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        if(i == triangle.size()-1)
            return triangle[i][j];
        if(i>=triangle.size()) return 0;
        if(j>=triangle[i].size()) return INT_MAX;
        if(dp[i][j]!=10005) return dp[i][j];
        int dwn = solve(triangle, i+1, j, dp);
        int dwnr = solve(triangle, i+1, j+1, dp);

        return dp[i][j] = triangle[i][j] + min(dwn, dwnr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //return solve(triangle,0,0);
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,10005));
        return solve(triangle,0,0,dp);
    }
};