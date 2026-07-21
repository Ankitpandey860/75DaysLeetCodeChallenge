class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(i>=matrix.size()) return 0;
        if(dp[i][j]!=1000005) return dp[i][j];
        int left=1000005;
        int right=1000005;
        int down=solve(matrix,i+1,j,dp);

        if(j-1>=0){
            left=solve(matrix,i+1,j-1,dp);
        }
        if(j+1<matrix[0].size()){
            right=solve(matrix,i+1,j+1,dp);
        }
        return dp[i][j]=min(left,min(down,right))+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1000005));
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};