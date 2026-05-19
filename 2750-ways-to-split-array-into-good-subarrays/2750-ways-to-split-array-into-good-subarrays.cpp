class Solution {
public:
const int mod=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int ans=1;
        int i=0;
        while(i<nums.size()&&nums[i]!=1){
            i++;
        }
        if(i>=nums.size()) return 0;
        int prev=i;
        i++;
        while(i<nums.size()){
            if(nums[i]==1){
                ans=(1ll*ans*1ll*(i-prev)%mod)%mod;
                prev=i;
            }
            i++;
        }
        return ans;
    }
};