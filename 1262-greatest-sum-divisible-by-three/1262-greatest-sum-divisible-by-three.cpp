class Solution {
public:
    int solve(vector<int>& nums,int i,int mod,vector<vector<int>>& dp){
        if(i>=nums.size()){
            return mod==0?0:INT_MIN;
        }
        if(dp[i][mod]!=-1) return dp[i][mod];
        int inc=solve(nums,i+1,(mod+nums[i])%3,dp);
        if(inc>=0){
            inc+=nums[i];
        }
        int exc=solve(nums,i+1,mod,dp);
        return dp[i][mod]=max(inc,exc);

    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return max(0,solve(nums,0,0,dp));
    }
};