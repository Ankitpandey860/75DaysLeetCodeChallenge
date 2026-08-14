class Solution {
public:
    int solve(vector<int>& stonevalue,int i,bool turn,vector<vector<int>>& dp){
        if(i>=stonevalue.size()) return 0;
        if(dp[i][turn]!=-1) return dp[i][turn];
        int sum=0;
        int ans;
        if(turn){
            ans=INT_MAX;
        }
        else{
            ans=INT_MIN;
        }
        for(int idx=i;idx<i+3&&idx<stonevalue.size();idx++){
            sum+=stonevalue[idx];
            int temp=solve(stonevalue,idx+1,turn^1,dp);
            if(turn){//alice - se dikhaunga
               ans=min(ans,temp-sum);
            }
            else{
                ans=max(ans,temp+sum);
            }
        }
        return  dp[i][turn]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans=solve(stoneValue,0,true,dp);
        if(ans<0){
            return "Alice";
        }
        if(ans>0){
            return "Bob";
        }
        return "Tie";
    }
};