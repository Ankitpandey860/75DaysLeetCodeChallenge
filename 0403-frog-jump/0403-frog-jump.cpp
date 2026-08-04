class Solution {
public:
    bool solve(vector<int>& stones,int k,int i,unordered_map<int,int>& mp,vector<vector<int>>& dp){
        if(i==stones.size()-1) return true;
        if(i>=stones.size()) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        bool kminus=false,kplus=false,origk=false;
        int curr=stones[i];
        if(mp.find(curr+k)!=mp.end()&&mp[curr+k]>i){
            origk=solve(stones,k,mp[curr+k],mp,dp);
        }
        if(mp.find(curr+k+1)!=mp.end()&&mp[curr+k+1]>i){
            kplus=solve(stones,k+1,mp[curr+k+1],mp,dp);
        }
        if(mp.find(curr+k-1)!=mp.end()&&mp[curr+k-1]>i){
            kminus=solve(stones,k-1,mp[curr+k-1],mp,dp);
        }
        return dp[i][k]=(kminus|origk|kplus);
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1) return false;
        int n=stones.size();
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(stones,1,1,mp,dp);
    }
};
