class Solution {
public:
    int solve(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>=n) return 0;
        //skip
        if(dp[i]!=-1) return dp[i];
        int skip=solve(i+1,n,nums,dp);
        int take=nums[i]+solve(i+2,n,nums,dp);
        return dp[i]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dpf(n+1,-1);
        vector<int>dpl(n+1,-1);
        int fst=solve(0,n-1,nums,dpf);
        int lst=solve(1,n,nums,dpl);
        return max(fst,lst);
    }
};