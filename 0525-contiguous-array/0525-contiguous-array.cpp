class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int diff=0;
        int len=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                diff++;
            }
            else{
                diff--;
            }
            if(mp.find(diff)!=mp.end()){
                int idx=mp[diff];
                len=max(len,i-idx);
            }
            else{
                mp[diff]=i;
            }
        }
        return len;
    }
};