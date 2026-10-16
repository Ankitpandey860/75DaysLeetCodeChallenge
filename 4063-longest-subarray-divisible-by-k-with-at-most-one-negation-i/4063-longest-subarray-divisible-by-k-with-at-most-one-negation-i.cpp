class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){

            nums[i]*=-1;
            int sum=0;
            
            mp[0]=-1;
            for(int j=0;j<n;j++){
                sum+=nums[j];
                sum%=k;
                if(sum<0) sum+=k;
                
                if(mp.find(sum)!=mp.end()){
                    ans=max(ans,j-mp[sum]);
                }
                else{
                    mp[sum]=j;
                }
            }
            nums[i]*=-1;
            mp.clear();
        }
        int sum=0;
        //unordered_map<int,int>mp;
        mp[0]=-1;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            sum%=k;
            if(sum<0) sum+=k;
            
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,j-mp[sum]);
            }
            else{
                mp[sum]=j;
            }
        }
        return ans;
    }
};