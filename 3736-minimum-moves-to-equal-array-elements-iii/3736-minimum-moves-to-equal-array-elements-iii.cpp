class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=nums[0];
        for(auto it:nums){
            maxi=max(maxi,it);
        }
        int ans=0;
        for(auto it:nums){
            ans+=(maxi-it);
        }
        return ans;
    }
};