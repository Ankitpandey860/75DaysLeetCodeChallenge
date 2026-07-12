class Solution {
public:
    int solve(int n,int m,int i,vector<int>& zero,vector<int>& one, vector<vector<vector<int>>>& dp){
        if(i>=zero.size()) return 0;
        if(dp[i][n][m]!=-1) return dp[i][n][m];
        int exc=solve(n,m,i+1,zero,one,dp);
        int cz=zero[i];
        int co=one[i];
        int inc=0;
        if(cz<=m&&co<=n){
            inc=1+solve(n-co,m-cz,i+1,zero,one,dp);
        }
        return dp[i][n][m]=max(inc,exc);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<int>zero(len,0),one(len,0);
        for(int i=0;i<len;i++){
            for(auto it:strs[i]){
                if(it=='0'){
                    zero[i]++;
                }
                else{
                    one[i]++;
                }
            }
        }
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solve(n,m,0,zero,one,dp);
    }
};