class Solution {
public:
    int solve(vector<vector<int>>& dungeon,int i,int j){
        if(i==dungeon.size()-1&&j==dungeon[0].size()-1){
            if(dungeon[i][j]>=0) return 0;
            return dungeon[i][j];
        }
        if(i>=dungeon.size()||j>=dungeon[0].size()){
            return INT_MIN;
        }
        int down=solve(dungeon,i+1,j);
        int right=solve(dungeon,i,j+1);
        if(down==INT_MIN&&right==INT_MIN){
            if(dungeon[i][j]>=0) return 0;
            else return dungeon[i][j];
        }
        int ans=max(down,right)+dungeon[i][j];
        if(ans>=0) return 0;
        return ans;
    }
    int memo(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>>& dp){
        if(i==dungeon.size()-1&&j==dungeon[0].size()-1){
            if(dungeon[i][j]>=0) return 0;
            return dungeon[i][j];
        }
        if(i>=dungeon.size()||j>=dungeon[0].size()){
            return INT_MIN;
        }
        if(dp[i][j]!=5) return dp[i][j];
        int down=memo(dungeon,i+1,j,dp);
        int right=memo(dungeon,i,j+1,dp);
        if(down==INT_MIN&&right==INT_MIN){
            if(dungeon[i][j]>=0) return dp[i][j]=0;
            else return dp[i][j]=dungeon[i][j];
        }
        int ans=max(down,right)+dungeon[i][j];
        if(ans>=0) return dp[i][j]=0;
        return dp[i][j]=ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //int ans= solve(dungeon,0,0);
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,5));
        int ans=memo(dungeon,0,0,dp);
        if(ans>=0){
            return 1;
        }
        return abs(ans)+1;
    }
};