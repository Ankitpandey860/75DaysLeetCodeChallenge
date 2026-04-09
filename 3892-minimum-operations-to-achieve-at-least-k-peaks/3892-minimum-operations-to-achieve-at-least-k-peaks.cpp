class Solution {
public:
    int solve(vector<int>& nums, int k,int i,int x,vector<vector<int>>& dp){
        if(k==0) return 0;
        if(i>=x) return INT_MAX;
        if(dp[k][i]!=-1) return dp[k][i];
        int n=nums.size();
        int cost=max(0,max(nums[(i+1)%n],nums[(n+i-1)%n])+1-nums[i]);
        int take=solve(nums,k-1,i+2,x,dp);
        if(take!=INT_MAX) take+=cost;
        int skip=solve(nums,k,i+1,x,dp);
        return dp[k][i]=min(skip,take);
    }
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp1(k+1,vector<int>(n+1,-1));
        vector<vector<int>>dpn(k+1,vector<int>(n+1,-1));
        int fst=solve(nums,k,0,n-1,dp1);
        int lst=solve(nums,k,1,n,dpn);
        int ans=min(fst,lst);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};