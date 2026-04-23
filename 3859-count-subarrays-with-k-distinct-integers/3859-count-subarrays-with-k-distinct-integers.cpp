class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int st1=0,st2=0,end=0;
        long long ans=0;
        int dst=0;
        int cnt=0;
        unordered_map<int,int>mp1,mp2;
        while(end<nums.size()){
            //incraseee
            if(mp1[nums[end]]==0)dst++;
            mp2[nums[end]]++;
            mp1[nums[end]]++;
            if(mp2[nums[end]]==m)cnt++;
            // shrinkkk
            while(dst>k){
                mp1[nums[st1]]--;
                if(mp1[nums[st1]]==0)dst--;
                st1++;
            }
            // m ko handlee krra
            while(cnt>=k){
                mp2[nums[st2]]--;
                if(mp2[nums[st2]]==m-1)cnt--;
                st2++;
            }
            if(st2>st1) ans+=(st2-st1);
            
            end++;
        }
        return ans;
    }
};