class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum = ((sum + nums[i]) % k + k) % k;
            int req=(k-(sum+k)%k)%k;
            /*if(mp.find(req)!=mp.end()){
                ans+=mp[req];
            }*/
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};