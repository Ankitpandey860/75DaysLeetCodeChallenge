class Solution {
public:
    int solve(int i,vector<int>& nums,int prev, vector<vector<int>>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int inc=0,exc=0;
        if(nums[i]%nums[prev]==0){
            inc=1+solve(i+1,nums,i,dp);
        }
        exc=solve(i+1,nums,prev,dp);
        return dp[i][prev]=max(inc,exc);
        
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1) return nums;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mxlen=0;
        for(int i=0;i<nums.size();i++){
            mxlen=max(mxlen,1+solve(i+1,nums,i,dp));
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int curr=1+solve(i+1,nums,i,dp);
            if(curr==mxlen){
                vector<int>temp;
                temp.push_back(nums[i]);
                int nxlen=mxlen-1;
                if(nxlen==0) return temp;
                for(int j=i+1;j<n;j++){
                    if(nums[j] % nums[i] == 0 &&
                            1 + solve(j+1, nums, j, dp) == nxlen){

                        temp.push_back(nums[j]);
                        i=j;
                        nxlen--;
                        if(nxlen==0) return temp;
                    }
                }
            }
        }
        return {};
    }
};