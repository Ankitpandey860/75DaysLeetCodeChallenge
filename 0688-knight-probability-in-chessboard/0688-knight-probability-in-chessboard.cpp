class Solution {
public:
    double solve(int n, int k, int row, int column,vector<vector<vector<double>>>& dp){
        if(k==0) return 1;
        if(dp[row][column][k]!=-1) return dp[row][column][k];
        double ans=0.00000;
        int moves[8][2] = {
                            { 2,  1},
                            {-2,  1},
                            { 2, -1},
                            {-2, -1},
                            { 1,  2},
                            {-1,  2},
                            { 1, -2},
                            {-1, -2}
                        };
        for(int i=0;i<8;i++){
            int nr=row+moves[i][0];
            int nc=column+moves[i][1];
            if(nr<n&&nr>=0&&nc<n&&nc>=0){
                ans+=solve(n,k-1,nr,nc,dp)*0.125;
            }
        }
        return dp[row][column][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(n,k,row,column,dp);
    }
};