class Solution {
public:
    int solve(vector<vector<int>>& pairs,int i,int pr, vector<vector<int>>& dp){
        if(i>=pairs.size()) return 0;
        if(dp[i][pr]!=-1) return dp[i][pr];
        // exc
        int exc=solve(pairs,i+1,pr,dp);
        int inc=0;
        if(pairs[i][0]>pairs[pr][1])
            inc=1+solve(pairs,i+1,i,dp);

        return dp[i][pr]=max(inc,exc);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int ans=0;
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<pairs.size();i++){
            ans=max(ans,1+solve(pairs,i+1,i,dp));
        }
        return ans;
    }
};