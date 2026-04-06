class Solution {
public:
    long long solve(vector<int>& nums,int i,bool skip,int &n,vector<vector<long long>>& dp){
        if(i>=n-1) return 0;
        if(dp[i][skip]!=-1) return dp[i][skip];
        long long cost=cost=max(0,max(nums[i+1],nums[i-1])+1-nums[i]);
        //long long take=LLONG_MAX,skp=LLONG_MAX;
        if(n&1){
           // cost=max(0,max(nums[i+1],nums[i-1])+1-nums[i]);
            return dp[i][skip]=cost+solve(nums,i+2,skip,n,dp);
        }
        else{
            if(skip){
                 
                    return dp[i][skip]=cost+solve(nums,i+2,1,n,dp);
                    
            }
            else{
                
                    long long take=cost+solve(nums,i+2,0,n,dp);
                
                    long long skp=solve(nums,i+1,true,n,dp);
                return dp[i][skip]=min(take,skp);
            }
        }
    }
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solve(nums,1,0,n,dp);
    }
};