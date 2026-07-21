class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int maxsum=INT_MIN;
        int totalsum=0;
        for(auto it:nums){
            sum+=it;
            totalsum+=it;
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        sum=0;
        int minsum=INT_MAX;
        for(auto it:nums){
            sum+=it;

            minsum=min(minsum,sum);
            if(sum>0){
                sum=0;
            }
        }
        int cirsum=totalsum==minsum?maxsum:totalsum-minsum;
        return max(maxsum,cirsum);
    }
};