class Solution {
public:
    int solve(vector<int>& prefix, int &k,int i,int j, vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int cst=INT_MAX;
        for(int idx=i;idx<j;idx+=k-1){
            int temp=solve(prefix,k,i,idx,dp)+solve(prefix,k,idx+1,j,dp);
            cst=min(cst,temp);
        }
        if((j-i)%(k-1)==0){
            cst+=prefix[j+1]-prefix[i];
        }
        return dp[i][j]= cst;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0) return -1;
        vector<int>prefix(n+1,0);
        prefix[0]=stones[0];
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+stones[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(prefix,k,0,n-1,dp);
    }
};