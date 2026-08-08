class Solution {
public:
    const int mod=1e9+7;
    int solve(int n,vector<int>& rollMax,int prev,int prevcnt, vector<vector<vector<int>>>& dp){
        if(n==0) return 1;
        if(dp[n][prev][prevcnt]!=-1) return dp[n][prev][prevcnt];
        long long ans=0;
        for(int i=1;i<=6;i++){
            if(i==prev){
                if(rollMax[i-1]>prevcnt){
                    ans+=solve(n-1,rollMax,i,prevcnt+1,dp);
                }
            }
            else{
                ans+=solve(n-1,rollMax,i,1,dp);
            }
            ans%=mod;
        }
        return dp[n][prev][prevcnt]=ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        long long ans=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(7,vector<int>(16,-1)));
        for(int i=1;i<=6;i++){
            
            ans+=solve(n-1,rollMax,i,1,dp);
            ans%=mod;
        }
        return ans;
    }
};