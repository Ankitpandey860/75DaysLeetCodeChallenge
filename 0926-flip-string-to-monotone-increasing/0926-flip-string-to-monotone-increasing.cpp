class Solution {
public:
    int solve(string &s,int i,bool z,vector<vector<int>>& dp){

        if(i>=s.length()) return 0;
        if(dp[i][z]!=-1) return dp[i][z];
        if(s[i]=='0'){
            if(z){
                return dp[i][z]= solve(s,i+1,z,dp);
            }
            else{
                
                return dp[i][z]=1+solve(s,i+1,false,dp);
            }
        }
        else{
            if(z){
                int flip=1+solve(s,i+1,z,dp);
                int cnt=solve(s,i+1,false,dp);
                return dp[i][z]=min(flip,cnt);
            }
            else{
                return dp[i][z]=solve(s,i+1,z,dp);
            }
        }
    }
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(s,0,true,dp);
    }
};