class Solution {
public:
    int solve(string& s, int k,int i,char ch,int cnt,vector<vector<vector<vector<int>>>>& dp){
     

        if(i>=s.length()){
            if(ch=='|') return 0;
            int len=0;
            if(cnt>1){
                string temp=to_string(cnt);
                len=temp.length();
            }
            return 1+len;
        }
        int prev = (ch == '|') ? 26 : ch - 'a';
        if(dp[i][k][prev][cnt]!=-1) return dp[i][k][prev][cnt];
        // dont delete
        int inc=INT_MAX,del=INT_MAX;
        if(ch=='|'||ch==s[i]){
           inc= solve(s,k,i+1,s[i],min(cnt+1,100),dp);
        }
        else{
            int len=0;
            if(cnt>1){
                string temp=to_string(cnt);
                len=temp.length();
            }
            inc=1+len+solve(s,k,i+1,s[i],1,dp);
        }
        if(k>0){
            del=solve(s,k-1,i+1,ch,cnt,dp);
        }
        return dp[i][k][prev][cnt]=min(del,inc);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.length();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(k+1,vector<vector<int>>(27,vector<int>(101,-1))));
        return solve(s,k,0,'|',0,dp);
    }
};