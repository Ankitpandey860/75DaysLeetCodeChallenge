class Solution {
public:
    int solve(vector<vector<char>>& seats,int i,int j,int prevmsk,int currmsk,vector<vector<vector<vector<int>>>>& dp) {
        if(i>=seats.size()||j>=seats[0].size()) return 0;
        if(dp[i][j][prevmsk][currmsk]!=-1) return dp[i][j][prevmsk][currmsk];
        int ans=0;
        int temp=0;
        bool upleft=false,upright=false,left=false,notbroken=false;
        if(i>0){
            if(j>0){
                upleft=prevmsk&(1<<(j-1));
            }
            if(j<seats[0].size()-1){
                    upright=prevmsk&(1<<(j+1));
            }
        }
        if(j>0){
            left=temp&(1<<(j-1));
        }
        if(seats[i][j]=='.') notbroken=true;
        // yeh include krke neeche
        if(!left&&!upleft&&!upright&&notbroken){
            ans=max(ans,1+solve(seats,i+1,0,currmsk|(1<<j),0,dp));
        }
        // yeh rehne do isi row se aage
        ans=max(ans,solve(seats,i,j+1,prevmsk,currmsk,dp));
        // mt include kro neeche jao
        ans=max(ans,solve(seats,i+1,0,currmsk,0,dp));
        
        // include krke right badho
        if(!left&&!upleft&&!upright&&notbroken){
            ans=max(ans,1+solve(seats,i,j+2,prevmsk,currmsk|(1<<j),dp));
        }
        return dp[i][j][prevmsk][currmsk]=ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size();
        int m=seats[0].size();
        int maxi=pow(2,m)-1;
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(maxi,vector<int>(maxi,-1))));

        return solve(seats,0,0,0,0,dp);
    }
};