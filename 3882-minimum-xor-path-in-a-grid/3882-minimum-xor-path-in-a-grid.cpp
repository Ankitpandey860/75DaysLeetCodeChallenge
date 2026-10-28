class Solution {
public:
    void traverse(vector<vector<int>>& grid,int i,int j,int& ans,int curr,vector<vector<vector<bool>>>& dp){
        if(i==grid.size()-1&&j==grid[0].size()-1){
            
            ans=min(ans,curr^grid[i][j]);
            return ;
        }
        if(i>=grid.size()||j>=grid[0].size()){
            return;
        }
        if(dp[i][j][curr]) return;
        
        traverse(grid,i,j+1,ans,curr^grid[i][j],dp);
        traverse(grid,i+1,j,ans,curr^grid[i][j],dp);
        dp[i][j][curr]=true;
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1&&m==1) return grid[0][0];
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(1024,0)));
        int ans=INT_MAX;
        traverse(grid,1,0,ans,grid[0][0],dp);
        traverse(grid,0,1,ans,grid[0][0],dp);
        return ans;
    }
};