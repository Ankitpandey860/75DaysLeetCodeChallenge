class Solution {
public:
    int dp[10001][6][11][11];
    const int m=pow(10,9)+7;
    int solve(int i,int n,string& s,int size ,int first , int second){
        if (i == n)
        {
            return dp[i][size][first+1][second+1] = size == 5;
        }
        if (dp[i][size][first+1][second+1] != -1)
        {
            return dp[i][size][first+1][second+1]%m;
        }
        int x=solve(i+1,n,s,size,first,second)%m;
        int y=0;
        if(size==0){
            y=solve(i+1,n,s,size+1,s[i]-'0',second)%m;
        }
        if(size==1){
            y=solve(i+1,n,s,size+1,first,s[i]-'0')%m;
        }
        if(size==2){
            y=solve(i+1,n,s,size+1,first,second)%m;
        }
        if(size==3&&s[i]-'0'==second){
            y=solve(i+1,n,s,size+1,first,second)%m;
        }
        if(size==4&&s[i]-'0'==first){
            y=solve(i+1,n,s,size+1,first,second)%m;
        }
        return dp[i][size][first+1][second+1]=(x%m + y%m)%m;
    }
    int countPalindromes(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, s.size(), s, 0, -1, -1)%m;
    }
};