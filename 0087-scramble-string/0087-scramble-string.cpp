class Solution {
public:
/*
    bool solve(int s1, int e1, int s2, int e2, string& str1, string& str2,vector<vector<vector<int>>>& dp) {
        if (e1 - s1 != e2 - s2)
            return false;
        if (e1 == s1) {
            if (e2 == s2 && str1[s1] == str2[s2]) {
                return true;
            }
            return false;
        }
        if (e2 == s2) {
            if (e1 == s1 && str1[s1] == str2[s2]) {
                return true;
            }
            return false;
        }
        if (e1 < s1 || e2 < s2)
            return false;
        
        int len=e2-s2+1;
        if(dp[s1][s2][len]!=-1) return dp[s1][s2][len];
        for (int i = 0; i < e1 - s1; i++) {
            bool llrr = solve(s1, s1 + i, s2, s2 + i, str1, str2,dp) &&
                        solve(s1 + i + 1, e1, s2 + i + 1, e2, str1, str2,dp);
            bool lrrl = solve(s1, s1 + i, e2 - i, e2, str1, str2,dp) &&
                        solve(s1 + i + 1, e1, s2, e2 - i - 1, str1, str2,dp);
            if (llrr || lrrl)
                return dp[s1][s2][len]=true;
        }
        return dp[s1][s2][len]=false;
    }*/
    bool solve(int s1,int s2,int len, string& str1, string& str2,vector<vector<vector<int>>>& dp) {
        
        if(len==1){
            return str1[s1]==str2[s2];
        }
        if(len<0) return false;
        
        //int len=e2-s2+1;
        if(dp[s1][s2][len]!=-1) return dp[s1][s2][len];
        for (int i = 1; i < len; i++) {
            bool llrr = solve(s1, s2,i, str1, str2,dp) &&
                        solve(s1 + i,s2 + i,len-i, str1, str2,dp);
            bool lrrl = solve(s1, s2+len-i,i,str1, str2,dp) &&
                        solve(s1 + i,s2,len-i, str1, str2,dp);
            if (llrr || lrrl)
                return dp[s1][s2][len]=true;
        }
        return dp[s1][s2][len]=false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n != m)
            return false;
        string temp1 = s1;
        string temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2)
            return false;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        //return solve(0, n - 1, 0, m - 1, s1, s2,dp);
        return solve(0,0,n,s1,s2,dp);
    }
};