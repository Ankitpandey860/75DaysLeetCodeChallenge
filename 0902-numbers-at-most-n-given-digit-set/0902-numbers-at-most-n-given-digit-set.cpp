class Solution {
public:
    int solve(vector<string>& digits, string& n,int idx,bool tght,bool ldzs,vector<vector<vector<int>>>& dp){
        if(idx==n.length()) return !ldzs;
        if(dp[idx][tght][ldzs]!=-1) return dp[idx][tght][ldzs];
        int ub=tght?n[idx]-'0':9;
        int ans=0;
        if(ldzs){
            ans+=solve(digits,n,idx+1,false,true,dp);
        }
        for(int i=0;i<digits.size();i++){
            int dig=digits[i][0] - '0';
            if(dig<=ub){

                ans+=solve(digits,n,idx+1,tght&(dig==ub),false,dp);
            }
            
        }
        return dp[idx][tght][ldzs]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        vector<vector<vector<int>>>dp(11,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(digits,s,0,true,true,dp);
    }
};