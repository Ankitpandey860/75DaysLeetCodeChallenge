class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*vector<int>temp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]-1]++;
            if(temp[nums[i]-1]>1){
                return nums[i];
            }
        }
        return 0;*/
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                return abs(nums[i]);
            }
            nums[(abs(nums[i])-1)]*=-1;
        }
        return 0;
    }
};