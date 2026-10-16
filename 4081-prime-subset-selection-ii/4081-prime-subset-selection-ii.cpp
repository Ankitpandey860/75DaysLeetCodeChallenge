class Solution {
public:
    int maxsum(vector<int>& primes,int s,int i,vector<vector<int>>& dp){
        if(i >= primes.size() || s == 0) return 0;
        if(dp[i][s]!=-1) return dp[i][s];
        // inc
        int inc=0;
        if(s>=primes[i]){
            inc=maxsum(primes,s-primes[i],i+1,dp)+primes[i];
        }
        // exc
        int exc=maxsum(primes,s,i+1,dp);
        return dp[i][s]=max(inc,exc);
    }
    int solve(vector<int>& primes,int i,int maxi,vector<vector<int>>& dp){
        if(maxi==0) return 0;
        if(i>=primes.size()) return INT_MAX;
        if(dp[i][maxi]!=-1) return dp[i][maxi];
        //inc 
        int inc=INT_MAX;
        if(primes[i]<=maxi)
            inc= solve(primes,i+1,maxi-primes[i],dp);
        if(inc!=INT_MAX) inc++;

        //exc
        int exc=solve(primes,i+1,maxi,dp);
        return dp[i][maxi]=min(inc,exc);
    }
    void build(vector<vector<int>>& dp,vector<int>& primes,int i,int maxi,int cnt,vector<int>& ans){
        if(i>=primes.size()||maxi==0) return;
        if(primes[i] <= maxi &&(primes[i]==maxi||dp[i][maxi] == cnt &&dp[i+1][maxi-primes[i]] == cnt-1)){
            ans.push_back(primes[i]);
            build(dp,primes,i+1,maxi-primes[i],cnt-1,ans);
        }
        else{
            build(dp,primes,i+1,maxi,cnt,ans);
        }
    }
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int>primes,ans;
        vector<bool>temp(n+1,true);
        for(int i=2;i<=n;i++){
            if(temp[i]){
                primes.push_back(i);
                for(int j=i;j<=n;j+=i){
                    temp[j]=false;
                }
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
        int maxi=maxsum(primes,s,0,dp);
        vector<vector<int>>dp2(n+1,vector<int>(maxi+1,-1));
        int minlen=solve(primes,0,maxi,dp2);
        build(dp2,primes,0,maxi,minlen,ans);
        return ans;
    }
};