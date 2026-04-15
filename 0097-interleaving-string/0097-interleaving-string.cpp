class Solution {
public:
    bool solve(string s1, string s2, string s3,int i,int j,vector<vector<int>>& dp){
        if(i+j==s3.length()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.length()){
            if(s2[j]==s3[i+j]){
                return dp[i][j]= solve(s1,s2,s3,i,j+1,dp);
            }
            else{
                return dp[i][j]= false;
            }
        }
        if(j==s2.length()){
            if(s1[i]==s3[i+j]){
                return dp[i][j]= solve(s1,s2,s3,i+1,j,dp);
            }
            else{
                return dp[i][j]=false;
            }
        }
        if(s1[i]==s3[i+j]&&s2[j]==s3[i+j]){
            bool fst=solve(s1,s2,s3,i+1,j,dp);
            bool sec=solve(s1,s2,s3,i,j+1,dp);
            return dp[i][j]=fst||sec;
        }
        if(s1[i]==s3[i+j]){
            return dp[i][j]=solve(s1,s2,s3,i+1,j,dp);
        }
        else if(s2[j]==s3[i+j]){
            return dp[i][j]=solve(s1,s2,s3,i,j+1,dp);
        }
        else{
            return dp[i][j]= false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};