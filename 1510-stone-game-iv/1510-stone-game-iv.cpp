class Solution {
public:
    bool solve(int n,vector<int>& dp){
        if(dp[n]!=-1) return dp[n];
        bool poss=true;
        int i=1;
        while(i*i<=n){
            poss=poss&solve(n-i*i,dp);
            i++;
        }
        return dp[n]=!poss;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};