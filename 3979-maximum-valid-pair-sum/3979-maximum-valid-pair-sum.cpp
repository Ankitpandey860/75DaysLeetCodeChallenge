class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefix[i]=maxi;
        }
        int ans=0;
        for(int i=k;i<n;i++){
            ans=max(ans,nums[i]+prefix[i-k]);
        }
        return ans;
    }
};