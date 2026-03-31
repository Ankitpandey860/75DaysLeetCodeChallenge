class Solution {
public:
    int MOD =1000000007;
    int distinctSubseqII(string s) {
        vector<int>alp(26,-1);
        int dup=0;
        int n=s.length();
       // vector<int>ans(n,0);
        vector<int>dp(n+1,0);
        dp[0]=1;
        //int ind=s[0]-'a';
        //alp[ind]=0;
        for(int i=0;i<n;i++){
            int ind=s[i]-'a';
            int remove=0;
            if(alp[ind]!=-1){
                remove =dp[alp[ind]];
                
            }
            alp[ind]=i;
           dp[i+1] = (2LL * dp[i] % MOD - remove + MOD) % MOD;
        }
        
        //return dp[n]-1;
        return (dp[n] - 1 + MOD) % MOD;
    }
};