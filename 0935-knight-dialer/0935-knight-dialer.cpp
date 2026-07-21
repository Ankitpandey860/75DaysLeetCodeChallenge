class Solution {
public:
    bool valid(int i,int j){
        int n=4;
        int m=3;
        if(i<0||j<0||i>=n||j>=m||(i==3&&j==0)||(i==3&&j==2)){
            return false;
        }
        return true;
    }
    const int mod=1e9+7;
    int arr[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    int solve(int step,int i,int j,int& n,int &m,vector<vector<vector<int>>>& dp){
        if(step==0) return 1;
        if(dp[i][j][step]!=-1) return dp[i][j][step];
        long long ans=0;
        for(auto it:arr){
            int nr=i+it[0];
            int nc=j+it[1];
            if(valid(nr,nc)){
                ans=(ans+solve(step-1,nr,nc,n,m,dp))%mod;
            }
        }
        return dp[i][j][step]=ans;
    }
    int knightDialer(int n) {
        int len=4;
        int col=3;
        long long ans=0;
        vector<vector<vector<int>>>dp(len,vector<vector<int>>(col,vector<int>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(valid(i,j)){
                    ans=(ans+solve(n-1,i,j,len,col,dp))%mod;
                }
            }
        }
        return ans;
    }
};