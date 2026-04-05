class Solution {
public:
    bool solve(string& s, string& p,int i1,int i2,vector<vector<int>>& dp){
        if(i1==s.length()&&i2==p.length()){
            return true;
        }
        if(i1==s.length()&&p[i2]!='*'){
            return false;
        }
        if(i1==s.length()&&p[i2]=='*'){
            return solve(s,p,i1,i2+1,dp);
        }
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        bool ans=false;
        if(p[i2]=='?'){
            ans=solve(s,p,i1+1,i2+1,dp);
        }
        else if(p[i2]=='*'){
            ans=solve(s,p,i1+1,i2+1,dp)|solve(s,p,i1+1,i2,dp)|solve(s,p,i1,i2+1,dp);
        }
        else if(p[i2]==s[i1]){
            ans=solve(s,p,i1+1,i2+1,dp);
        }
        else{
            return false;
        }
        return dp[i1][i2]=ans;
    }
    bool tab(string& s, string& p){
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+2,vector<int>(m+2,false));
        dp[n][m]=true;
        for(int i1=n;i1>=0;i1--){
            for(int i2=m;i2>=0;i2--){
                if(i1==n&&i2==m) continue;
                if(i1==s.length()&&p[i2]=='*'){
                    dp[i1][i2]= dp[i1][i2+1];
                    continue;
                }
                
                bool ans=false;
                if(i2<m&&p[i2]=='?'){
                    ans=dp[i1+1][i2+1];
                }
                else if(i2<m&&p[i2]=='*'){
                    ans=dp[i1+1][i2+1]|dp[i1+1][i2]|dp[i1][i2+1];
                }
                else if(i2<m&&i2<m&&p[i2]==s[i1]){
                    ans=dp[i1+1][i2+1];
                }
                
                dp[i1][i2]=ans;
            }
        }
        return dp[0][0];
    }
    bool isMatch(string s, string p) {
        /*int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
        return solve(s,p,0,0,dp);*/
        if(s.empty()){
            int i=0;
            while(i<p.length()){
                if(p[i]!='*') return false;
                i++;
            }
            
            return true;
        }
        return tab(s,p);
    }
};