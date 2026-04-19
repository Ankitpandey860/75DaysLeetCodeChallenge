class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int req=sum-k;
            if(mp.find(req)!=mp.end()){
                cnt+=mp[req];
            }
            mp[sum]++;
        }
        return cnt;
    }
};