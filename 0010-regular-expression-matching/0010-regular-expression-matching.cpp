class Solution {
public:
    bool solve(string& s,string& p ,int i,int j,vector<vector<int>>& dp){
        if(i>=s.length()&&j>=p.length()) return true;
        if(j>=p.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool currMatch = i < s.length() && (p[j] == '.' || s[i] == p[j]);
        if(j+1<p.length()&&p[j+1]=='*'){
            bool exc=solve(s,p,i,j+2,dp);
            bool inc=currMatch&&solve(s,p,i+1,j,dp);
            return dp[i][j]=exc||inc;
        }
        else if(currMatch){
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=false;
        }
    } 
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0,dp);
    }
};