class Solution {
public:
    pair<int,int> solve(vector<int>& stoneValue,int i,int m, bool alice,vector<vector<vector<pair<int,int>>>>& dp){
        if(i>=stoneValue.size()) return make_pair(0,0);
        int n=stoneValue.size();
        if(dp[i][m][alice]!=make_pair(-1,-1)) return dp[i][m][alice];
        int sum=0;
        auto ans=make_pair(0,0);
        
        int curr=0;
        for(int j=0;j<2*m&&i+j<stoneValue.size();j++){
            sum+=stoneValue[i+j];
            if(alice){
                auto curr=solve(stoneValue,i+j+1,min(n-1,max(j+1,m)),alice^1,dp);
                curr.first+=sum;
                if(curr.first>ans.first){
                    
                    ans=curr;
                }
                
            }
            else{
                auto curr=solve(stoneValue,i+j+1,min(n-1,max(j+1,m)),alice^1,dp);
                curr.second+=sum;
                if(curr.second>ans.second){
                    
                    ans=curr;
                }
            }
        }
        return dp[i][m][alice]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<pair<int,int>>>> dp(
            n,
            vector<vector<pair<int,int>>>(n + 1,
                vector<pair<int,int>>(2, {-1, -1}))
        );
        auto temp=solve(piles,0,1,true,dp);
        return temp.first;
    }
};