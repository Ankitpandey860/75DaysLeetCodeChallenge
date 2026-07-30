class Solution {
public:
    int solve(vector<int>& cuts,int l,int r,vector<vector<int>>& dp){
        if(l+1==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=INT_MAX;
        for(int i=l+1;i<r;i++){
            
            int len=cuts[r]-cuts[l];
            int temp=solve(cuts,l,i,dp)+solve(cuts,i,r,dp);
            if(temp!=INT_MAX)
                ans=min(ans,len+temp);

        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(cuts,0,m-1,dp);
    }
};