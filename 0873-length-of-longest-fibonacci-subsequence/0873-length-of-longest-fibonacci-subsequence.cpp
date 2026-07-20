class Solution {
public:
    int solve(vector<int>& arr,int i,int j,unordered_map<int,int>& mp,vector<vector<int>>& dp){
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int req=arr[j]-arr[i];

        if(mp.find(req)!=mp.end()&&mp[req]<i){
            return dp[i][j]=1+(solve(arr,mp[req],i,mp,dp));
        }
        return dp[i][j]=ans;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans=max(ans,solve(arr,i,j,mp,dp));
            }
        }
        return ans==0?0:ans+2;
    }
};