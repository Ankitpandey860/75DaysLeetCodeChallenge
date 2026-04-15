class Solution {
public:
    int n;
    vector<vector<vector<vector<int>>>> dp;

    int solve(int i1,int j1,int i2,int j2,
              vector<vector<int>>& grid) {

        if(i1>=n || j1>=n || i2>=n || j2>=n ||
           grid[i1][j1]==-1 || grid[i2][j2]==-1)
            return INT_MIN;

        if(i1==n-1 && j1==n-1 &&
           i2==n-1 && j2==n-1)
            return grid[i1][j1];

        if(dp[i1][j1][i2][j2] != -1)
            return dp[i1][j1][i2][j2];

        int curr1 = grid[i1][j1];
        int curr2 = grid[i2][j2];

        grid[i1][j1] = 0;
        grid[i2][j2] = 0;

        int f1 = solve(i1, j1+1, i2, j2+1, grid);
        int f2 = solve(i1+1, j1, i2+1, j2, grid);
        int f3 = solve(i1, j1+1, i2+1, j2, grid);
        int f4 = solve(i1+1, j1, i2, j2+1, grid);

        int ans = max(max(f1,f2), max(f3,f4));

        grid[i1][j1] = curr1;
        grid[i2][j2] = curr2;

        if(ans == INT_MIN)
            return dp[i1][j1][i2][j2] = INT_MIN;

        if(i1 == i2 && j1 == j2)
            return dp[i1][j1][i2][j2] = ans + curr1;
        else
            return dp[i1][j1][i2][j2] = ans + curr1 + curr2;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        dp = vector<vector<vector<vector<int>>>>(
            n, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    n, vector<int>(n, -1))));

        int ans = solve(0,0,0,0,grid);
        return max(0, ans);
    }
};