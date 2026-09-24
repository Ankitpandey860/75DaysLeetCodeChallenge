class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]>0||nums[j]<0) return -1;
            if(abs(nums[i])==nums[j]) return nums[j];
            int l=abs(nums[i]);
            int r=nums[j];
            if(l<r){
                j--;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};