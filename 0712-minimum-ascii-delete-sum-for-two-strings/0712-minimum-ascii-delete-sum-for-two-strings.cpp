class Solution {
public:
    int solve(string& s1, string& s2 ,int i,int j,vector<vector<int>>& dp){
        if(i>=s1.length()&&j>=s2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=s1.length()){
            int second=(int)(s2[j]);
            return dp[i][j]=second+solve(s1,s2,i,j+1,dp);
        }
        if(j>=s2.length()){
            int second=(int)(s1[i]);
            return dp[i][j]=second+solve(s1,s2,i+1,j,dp);
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
        }
        else {
            int ans=INT_MAX;
            int first=(int)(s1[i]);
            int second=(int)(s2[j]);
            int delf=solve(s1,s2,i+1,j,dp);
            int dels=solve(s1,s2,i,j+1,dp);
            if(delf!=INT_MAX){
                delf+=first;
            }
            if(dels!=INT_MAX){
                dels+=second;
            }
            ans=min(ans,min(dels,delf));
            return dp[i][j]=ans;
        }
    }
    int minimumDeleteSum(string& s1, string& s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};