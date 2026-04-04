class Solution {
public:
    vector<int> next, prev;
    const int mod=1000000007;
    void compute(string& s){
        int n = s.length();

        

        unordered_map<char,int> mp;

        // build prev[]
        // prev[i] = previous occurrence of s[i]
        for(int i = 0; i < n; i++) {
            if(mp.count(s[i]))
                prev[i] = mp[s[i]];
            else
                prev[i] = -1;

            mp[s[i]] = i;
        }

        mp.clear();

        // build next[]
        // next[i] = next occurrence of s[i]
        for(int i = n - 1; i >= 0; i--) {
            if(mp.count(s[i]))
                next[i] = mp[s[i]];
            else
                next[i] = -1;

            mp[s[i]] = i;
        }
    }
    int solve(string& s,int i,int j,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]!=s[j]){
            ans = 1ll*(
                    1ll*solve(s,i+1,j,dp)%mod
                    + 1ll*solve(s,i,j-1,dp)%mod
                    - 1ll*solve(s,i+1,j-1,dp)%mod
                    + mod
                ) % mod;
        }
        else{
            int low = next[i];
            int high = prev[j];
            if(low == -1 || low > high){
                ans=((2ll*solve(s,i+1,j-1,dp))%mod+2%mod)%mod;
            }
            else if(low==high){
                ans=((2ll*solve(s,i+1,j-1,dp))%mod+1%mod)%mod;
            }
            else if(low<high){
                ans=((2ll*solve(s,i+1,j-1,dp))%mod-solve(s,low+1,high-1,dp)%mod+mod)%mod;
            }
        }
        return dp[i][j]=ans;
    }
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        next.resize(n);
        prev.resize(n);
        compute(s);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp)%mod;
    }
};