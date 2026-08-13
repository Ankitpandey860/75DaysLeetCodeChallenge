class Solution {
public:
    int solve(vector<int>& boxes,int i,int j,int k,vector<vector<vector<int>>>& dp){
        if(i>j) return 0;
        //if(i==j) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int li=i;
        int kh=k;
        while(li+1<=j&&boxes[li+1]==boxes[li]){
            li++;
            k++;
        }
        int deletecurronly=(k+1)*(k+1)+solve(boxes,li+1,j,0,dp);
        int ans=0;
        // hrr index pe dekhtaa huuu ki isee htauu ya na htauu yahi ruk jau
        for(int ri=li+1;ri<=j;ri++){
            if(boxes[ri]==boxes[li]){
                ans=max(ans,solve(boxes,ri,j,k+1,dp)+solve(boxes,li+1,ri-1,0,dp));
            }
        }
        return dp[i][j][kh]=max(ans,deletecurronly);
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(boxes,0,n-1,0,dp);
    }
};