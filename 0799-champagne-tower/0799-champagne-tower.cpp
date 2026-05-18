class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = query_row;
        vector<vector<double>> dp(n+2,vector<double>(n+2,0));
        dp[0][0]=poured;
        for (int i = 0; i <=n; i++) {
            for (int j = 0; j <= i; j++) {
                if(dp[i][j]>1){
                    double rem=dp[i][j]-1;
                    double add=rem/2.000000;
                    dp[i+1][j]+=add;
                    dp[i+1][j+1]+=add;
                    dp[i][j]=1;
                }
            }
        }
        return dp[n][query_glass];
    }
};