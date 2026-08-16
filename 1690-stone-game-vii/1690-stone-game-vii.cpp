class Solution {
public:
    int solve(vector<int>& stones,int i,int j,vector<int>& prefix,vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int prev=i>0?prefix[i-1]:0;
        int tillj=prefix[j];
        int total=tillj-prev;
        int left=total-stones[i]-solve(stones,i+1,j,prefix,dp);
        int right=total-stones[j]-solve(stones,i,j-1,prefix,dp);
        return dp[i][j]= max(left,right);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(stones,0,n-1,prefix,dp);
    }
};