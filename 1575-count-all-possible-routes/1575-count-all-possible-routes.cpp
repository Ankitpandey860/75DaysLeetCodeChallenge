class Solution {
public:
    const int mod=1e9+7;
    int solve(vector<int>& locations, int curr, int finish, int fuel,vector<vector<int>>& dp){
        if(fuel<0) return 0;
        if(dp[curr][fuel]!=-1) return dp[curr][fuel];
        long long ans=0;
        
        if(curr==finish) ans++;
        if(fuel==0&&curr!=finish) return 0;
        
        for(int i=0;i<locations.size();i++){
            if(i==curr) continue;
            int cost=abs(locations[i]-locations[curr]);
            ans+=solve(locations,i,finish,fuel-cost,dp);
        }
        return dp[curr][fuel]=ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};