class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(i>=matrix.size()||j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(matrix[i][j]==1){
            int right=solve(matrix,i,j+1,dp);
            int down=solve(matrix,i+1,j,dp);
            int dig=solve(matrix,i+1,j+1,dp);
            return dp[i][j]= 1+min(right,min(down,dig));

        }
        return dp[i][j]=0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(matrix,i,j,dp);
            }
        }
        return ans;
    }
};