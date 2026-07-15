class Solution {
public:

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>grid(n,vector<int>(n,1));
        for(auto it:mines){
            int i=it[0];
            int j=it[1];
            grid[i][j]=0;
        }
        vector<vector<int>> left(n, vector<int>(n,0));
        vector<vector<int>> right(n, vector<int>(n,0));
        vector<vector<int>> up(n, vector<int>(n,0));
        vector<vector<int>> down(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    left[i][j]=0;
                else if(j==0)
                    left[i][j]=1;
                else
                    left[i][j]=left[i][j-1]+1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)
                    right[i][j]=0;
                else if(j==n-1)
                    right[i][j]=1;
                else
                    right[i][j]=right[i][j+1]+1;
                }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]==0)
                    up[i][j]=0;
                else if(i==0)
                    up[i][j]=1;
                else
                    up[i][j]=up[i-1][j]+1;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                if(grid[i][j]==0)
                    down[i][j]=0;
                else if(i==n-1)
                    down[i][j]=1;
                else
                    down[i][j]=down[i+1][j]+1;
                
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               ans=max(ans,min(down[i][j],min(up[i][j],min(left[i][j],right[i][j]))));
            }
        }
        return ans;
        
    }
};