class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=0;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};