class Solution {
public:
    int solve(vector<int>& nums, int sum,int i,vector<vector<int>>& dp){
        if(sum==0) return 0;
        
        if(i>=nums.size()){
            if(sum==0) return 0;
            return INT_MAX;
        }
        if(sum<0) return INT_MAX;
        if(dp[i][sum]!=-1) return dp[i][sum];
        // mul
        int skip=solve(nums,sum,i+1,dp);
        int mul=INT_MAX,div=INT_MAX;
        int temp=nums[i];
        int j=0;
        while(temp*(1LL << j)<=sum){
            int curr=solve(nums,sum-temp*(1LL << j),i+1,dp);
            if (curr != INT_MAX) {
                mul = min(mul, curr + j);
            }
            j++;
        }
        temp=nums[i];
        j=1;
        while(temp / (1 << j) > 0){
            int curr=solve(nums,sum - (temp / (1 << j)),i+1,dp);
            if(curr!=INT_MAX) curr+=j;
            j++;
            div=min(curr,div);
        }
        return  dp[i][sum]=min(div,min(mul,skip));
    }
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=solve(nums,sum,0,dp);
        return ans==INT_MAX?-1:ans;
    }
};