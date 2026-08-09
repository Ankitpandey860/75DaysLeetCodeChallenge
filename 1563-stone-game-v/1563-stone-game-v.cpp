class Solution {
public:
    int solve(vector<int>& prefix,int i,int j,vector<vector<int>>& dp){
        if(j-i<=0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<j;k++){
            int left=prefix[k];
            if(i>0){
                left-=prefix[i-1];
            }
            int right=prefix[j]-prefix[k];
            if(left==right){
                int lremove=right+solve(prefix,k+1,j,dp);
                int rremove=left+solve(prefix,i,k,dp);
                ans=max(ans,max(lremove,rremove)) ;
            }
            else if(left>right){
                ans=max(ans,right+solve(prefix,k+1,j,dp));
            }
            else{
                ans=max(ans,left+solve(prefix,i,k,dp));
            }
            
        }
        return dp[i][j]= ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>prefix(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stoneValue[i];
            prefix[i]=sum;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(prefix,0,n-1,dp);
    }
};