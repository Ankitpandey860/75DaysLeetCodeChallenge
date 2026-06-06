class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int elem=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=elem){
                count--;
            }
            else{
                count++;
            }
            if(count<0){
                count=1;
                elem=nums[i];
            }
        }
        return elem;
    }
};