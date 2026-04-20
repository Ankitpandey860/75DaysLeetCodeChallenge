class Solution {
public:
    int solve(string& num,int idx,bool tight,int cnt,vector<vector<vector<int>>>& dp){
        if(idx==num.length()) return cnt;
        if(dp[idx][cnt][tight]!=-1) return dp[idx][cnt][tight];
        int ub=tight?num[idx]-'0':9;
        int res=0;
        for(int i=0;i<=ub;i++){
            if(tight&&i==ub){
                if(i==1)
                    res+=solve(num,idx+1,true,cnt+1,dp);
                else
                    res+=solve(num,idx+1,true,cnt,dp);
            }
            else{
                if(i==1)
                    res+=solve(num,idx+1,false,cnt+1,dp);
                else
                    res+=solve(num,idx+1,false,cnt,dp);
            }
        }
        return dp[idx][cnt][tight]=res;
    }
    int countDigitOne(int n) {
        string num=to_string(n);
        int len=num.length();
        vector<vector<vector<int>>>dp(len,vector<vector<int>>(10,vector<int>(2,-1)));
        return solve(num,0,true,0,dp);
    }
};