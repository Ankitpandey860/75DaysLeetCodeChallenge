class Solution {
public:
bool pal(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s,int l,int r){
        if(l>=r||l<0||r>=s.length()) return 0;
        int left = pal(s,l,r);
        //int right = pal(s.substr(j + 1));
        if(left){
            return 0;
        }
        int ans=INT_MAX;
        if(!left){
            for(int i=l;i<r;i++){
                ans=min(ans,solve(s,l,i)+solve(s,i+1,r));
            }
        }
        return ans+1;
    }
    int memo(string& s,int l,int r,vector<vector<int>>& dp){
        if(l>=r||l<0||r>=s.length()) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int left = pal(s,l,r);
        //int right = pal(s.substr(j + 1));
        if(left){
            return dp[l][r]=0;
        }
        int ans=INT_MAX;
        if(!left){
            for(int i=l;i<r;i++){
                if(pal(s,l,i))
                    ans=min(ans,memo(s,i+1,r,dp));
            }
        }
        return dp[l][r]=ans+1;
    }
    int minCut(string s) {
        int n=s.length();
         
         vector<vector<int>>dp(n,vector<int>(n,-1));
         return memo(s,0,n-1,dp);

    }
};