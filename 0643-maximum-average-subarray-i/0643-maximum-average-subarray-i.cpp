class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0.000000;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ans=sum/(k*1.000000);
        for(int i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            ans=max(ans,sum/(k*1.000000));
        }
        return ans;
    }
};