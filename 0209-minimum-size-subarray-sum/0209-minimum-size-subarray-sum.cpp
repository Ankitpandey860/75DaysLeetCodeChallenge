class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        while(j<nums.size()&&i<nums.size()){
            while(sum<target&&j<nums.size()){
                sum+=nums[j];
                j++;
            }
            while(sum>=target&&i<=j){
                ans=min(ans,j-i);
                sum-=nums[i];
                i++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};