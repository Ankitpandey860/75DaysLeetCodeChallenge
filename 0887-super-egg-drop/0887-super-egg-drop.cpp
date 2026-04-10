class Solution {
public:
    int solve(int n,int k,vector<vector<int>>& dp){
        if(k==1||n<=1) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        int ans=100000;
        int low=1,high=n;
        while(low<=high){
            int mid=(low+high)/2;
            int left=solve(mid-1,k-1,dp);
            int right=solve(n-mid,k,dp);
            int temp=max(left,right)+1;
            if(left<right){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            ans=min(ans,temp);
        }
        return dp[n][k]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};