class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) total++;
            else if(nums[i]<target) small++;
        }
        vector<int> ans;
        for(int i=0;i<total;i++){
            ans.push_back(small+i);
        }
        return ans;
    }
};