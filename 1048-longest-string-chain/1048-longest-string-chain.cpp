class Solution {
public:
    bool poss(string& a,string& b){
        bool allowed=true;
        int i=0,j=0;
        while(i<a.length()&&j<b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(allowed){
                    j++;
                    allowed=false;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    int solve(vector<string>& v,int i,int pi,vector<vector<int>>& dp){
        if(i>=v.size()) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int inc=0,exc=0;
        if(pi==-1||((v[i].length()-v[pi].length()==1)&&poss(v[pi],v[i]))){
            inc=1+solve(v,i+1,i,dp);
        }
        exc=solve(v,i+1,pi,dp);
        return dp[i][pi+1]=max(inc,exc);
    }
    int longestStrChain(vector<string>& v) {
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(v,0,-1,dp);
    }
};