class Solution {
public:
    pair<int,int> solve(vector<int>& nums,int i,int j,vector<vector<pair<int,int>>>& dp){
        if(i>=nums.size()) return {0,1};
        if(dp[i][j] != make_pair(-1, -1)) return dp[i][j];
        auto exc=solve(nums,i+1,j,dp);
        pair<int,int> take = {INT_MIN,0};
        if(nums[i]>nums[j]){
            take=solve(nums,i+1,i,dp);
            take.first+=1;
        }
        if(take.first>exc.first) return dp[i][j]=take;
        else if(take.first<exc.first) return dp[i][j]=exc;
        else return dp[i][j]={take.first,take.second+exc.second};

    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int> ans={-1,-1};
        for(int i=0;i<nums.size();i++){
            auto temp=solve(nums,i+1,i,dp);
            temp.first++;
            if(temp.first>ans.first){
                ans=temp;
            }
            else if(temp.first==ans.first){
                ans.second+=temp.second;
            }
        }
        return ans.second;
    }
};