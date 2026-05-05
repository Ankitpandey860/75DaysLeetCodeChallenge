class Solution {
public:
    int solve(string& s, string& t,int i1,int i2,vector<vector<int>>& dp){
        if(i2>=t.length()) return 1;
        if(i1>=s.length()) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        int inc=0;
        if(s[i1]==t[i2]){
            inc=solve(s,t,i1+1,i2+1,dp);
        }
        int exc=solve(s,t,i1+1,i2,dp);
        return dp[i1][i2]=inc+exc;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,0,0,dp);
    }
};