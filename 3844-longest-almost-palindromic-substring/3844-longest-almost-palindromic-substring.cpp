class Solution {
public:
    int solve(string& s,int l,int r,vector<vector<int>>& dp){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]=solve(s,l+1,r-1,dp);
        }
        return dp[l][r]=1+min(solve(s,l+1,r,dp),solve(s,l,r-1,dp));
    }
    int almostPalindromic(string s) {
        int ans=0;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                int len=j-i+1;
                if(solve(s,i,j,dp)<=1){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};