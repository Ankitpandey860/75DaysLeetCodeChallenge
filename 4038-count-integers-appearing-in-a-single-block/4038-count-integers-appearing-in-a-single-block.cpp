class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(j<nums.size()&&nums[j]==nums[i]){
                j++;
            }
            mp[nums[i]]++;
            i=j-1;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==1) ans++;
        }
        return ans;
    }
};