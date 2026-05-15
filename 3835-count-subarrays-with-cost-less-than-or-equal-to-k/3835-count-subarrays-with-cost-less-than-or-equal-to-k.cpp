class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        deque<int> minq,maxq;
        int l=0;
        long long ans=0;
        for(int r=0;r<nums.size();r++){
            while(!maxq.empty()&&nums[maxq.back()]<nums[r]){
                maxq.pop_back();
            }
            maxq.push_back(r);
            while(!minq.empty()&&nums[minq.back()]>nums[r]){
                minq.pop_back();
            }
            minq.push_back(r);
            while(l<=r&&((1ll*nums[maxq.front()]-1ll*nums[minq.front()])*1ll*(r-l+1))>k){
                while(maxq.front()<=l){
                    maxq.pop_front();
                }
                while(minq.front()<=l){
                    minq.pop_front();
                }
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};