class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& colors,int i,vector<long long>& dp){
        if(i>=nums.size()) return 0;
        int color=colors[i];
        if(i==colors.size()-1){
            return nums[i];
        }
        if(dp[i]!=-1) return dp[i];
        else if(colors[i]==colors[i+1]){
            return dp[i]=max(1ll*solve(nums,colors,i+2,dp)+1ll*nums[i],solve(nums,colors,i+1,dp));
        }
        else{
            return dp[i]=1ll*solve(nums,colors,i+1,dp)+nums[i];
        }
       
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long>dp(nums.size(),-1);
        return solve(nums,colors,0,dp);
    }
};