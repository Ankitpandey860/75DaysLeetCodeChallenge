class Solution {
public:
    int sum;
    int solve(int i,int diff,vector<int>& rods, vector<vector<int>>& dp){
        if(i>=rods.size()){
            if(diff==0) return 0;
            return INT_MIN;
        }
        if(dp[i][diff]!=-1) return dp[i][diff];
        int addsame=rods[i]+solve(i+1,diff+rods[i],rods,dp);
        int addother=rods[i]+solve(i+1,abs(diff-rods[i]),rods,dp);
        int skip=solve(i+1,diff,rods,dp);
        return dp[i][diff]=max(skip,max(addsame,addother));
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<vector<int>>dp(n,vector<int>(5001,-1));
        return solve(0,0,rods,dp)/2;
    }
};