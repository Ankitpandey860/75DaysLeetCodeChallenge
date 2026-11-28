class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int dis=0;
        long long ans=0,sum=0;

        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1) dis++;
        }
        if(dis==k) ans=max(sum,ans);
        for(int i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1) dis++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0) dis--;
            if(dis==k) ans=max(sum,ans);
        }
        return ans;
    }
};