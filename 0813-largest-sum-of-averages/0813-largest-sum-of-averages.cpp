class Solution {
public:
    double calc(vector<int>& prefix,int i,int j){
        double psum=i>0?prefix[i-1]:0;
        double sum=(prefix[j]-psum)*1.000000;
        double len=(j-i+1)*1.000000;
        return sum/len;
    }
    double solve(vector<int>& prefix,int i,int j,int k,vector<vector<vector<double>>>& dp){
        if(j>=prefix.size()){
            return calc(prefix,i,j-1);    
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        // not partition
        double exc=solve(prefix,i,j+1,k,dp);
        double inc=0.000000;
        if(k>1){
            inc=calc(prefix,i,j)+solve(prefix,j+1,j+1,k-1,dp);
        }
        return dp[i][j][k]= max(inc,exc);
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(prefix,0,0,k,dp);
    }
};