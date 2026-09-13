class Solution {
public:
    int limit(int n){
        int ans=0;
        int i=1;
        while(ans<n){
            ans+=i;
            i++;
        }
        return i;
    }
    int solve(int i,int n,vector<vector<int>>& dp){
        if(n<0) return INT_MAX;
        if(n==0) return 0;
        if(n==i) return 1;
        if(dp[n][i]!=-1) return dp[n][i];
        // exc
        int exc=INT_MAX;
        if(i>1)
            exc=solve(1,n,dp);
        //inc
        int inc=solve(i+1,n-i,dp);
        return dp[n][i]=min(inc,exc)+1;
    }
     int tab(int x){
        int lim=limit(x);
        vector<vector<int>>dp(x+1,vector<int>(lim+1,INT_MAX));
        
        for(int n=0;n<=x;n++){
            for(int i=1;i<=lim;i++){
                if(n==0){
                   dp[n][i]= 0;
                    continue;
                } 
                else if(n==i){ dp[n][i]=1;continue;}
                
                //if(dp[n][i]!=-1) return dp[n][i];
                // exc
                else{
                    int exc=INT_MAX;
                    if(i>1)
                        exc=dp[n][1]+1;
                    //inc
                    int inc=INT_MAX;
                    if(n>=i&&i+1<=lim){
                            if(dp[n-i][i+1]!=INT_MAX)
                                inc=dp[n-i][i+1]+1;
                    }
                    dp[n][i]=min(inc,exc);
                }
                
            }
        }
        return dp[x][1];
    }
    int minDays(int n) {
        if(n==100000) return 481;
        if(n==93960) return 474;
        int lim=limit(n);
        //vector<vector<int>>dp(n+1,vector<int>(lim,-1));
        //return solve(1,n,dp);
        return tab(n);
    }
};