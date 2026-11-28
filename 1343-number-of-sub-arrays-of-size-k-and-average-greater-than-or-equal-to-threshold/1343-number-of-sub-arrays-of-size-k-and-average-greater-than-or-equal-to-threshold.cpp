class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        double ans=0.000000;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ans=sum/(k*1.000000);
        int cnt=0;
        if(ans>=threshold) cnt++;
        for(int i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            ans=sum/(k*1.000000);
            if(ans>=threshold) cnt++;
        }
        return cnt;
    }
};